#include <stdio.h>
#include <stdlib.h>
#ifdef __WIN32__
#include <winsock2.h>
#include <windows.h>
#include <stdint.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#endif

typedef struct s_SocketInfo {
    int serverSocket;
    int clientSocket;
    int connectedSocket;
    int portNumber;
} SocketInfo;
SocketInfo *socketPortList = NULL;

int init()
{
#ifdef __WIN32__
    WORD minimumVersion = MAKEWORD(2, 0);
    WSADATA data;
    return (WSAStartup(minimumVersion, &data) != SOCKET_ERROR);
#else
    return 1;
#endif
}

void appShutdown()
{
#ifdef __WIN32__
    WSACleanup();
#endif
}

/**
 * Given port, return 0 for success, 1 for failure
 */
int createServerSocket(int port)
{
    struct sockaddr_in saddr;
    int s = socket(PF_INET, SOCK_STREAM, 0);
    if (s < 0)
        return -1;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons((uint16_t)(port & 0xFFFF));
    saddr.sin_addr.s_addr = htonl (INADDR_ANY);
    if (bind (s, (struct sockaddr *)&saddr, sizeof(saddr)) < 0)
        return -2;
    if (listen(s, 1) < 0)
        return -3;
    return s; // success!!
}

int createClientSocket(int port)
{
    struct sockaddr_in saddr;
    int s = socket(PF_INET, SOCK_STREAM, 0);
    if (s < 0)
        return -1;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons((uint16_t)(port & 0xFFFF));
    saddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if (connect(s, (struct sockaddr *)&saddr, sizeof(saddr)) < 0)
        return -4;
    return s; // success!!
}

int main(int argc, char **argv)
{
    int i;
    int sleepyTime = 10;

    if (argc < 3) {
        fprintf(stderr,"Usage: %s <num-sockets> <base-port> [<sleep-time>]\n",argv[0]);
        fprintf(stderr,"Where sleep time is how long the the program keeps sockets open (in seconds)\n");
        fprintf(stderr,"  (default is 10 seconds)\n");
        return 1;
    }

    int numSockets = atoi(argv[1]);
    int basePort = atoi(argv[2]);
    if (argc > 3)
        sleepyTime = atoi(argv[3]);

    init();
    fprintf(stderr,"Number of Sockets: %d\nBase Port Number: %d\nSleep time: %d\n",numSockets,basePort,sleepyTime);
    socketPortList = (SocketInfo *)malloc(sizeof(SocketInfo) * numSockets);

    int count = 0;
    for (i = 0; i < numSockets; i++) {
        int portNum = i + basePort;
        int result = createServerSocket(i + basePort);
        if (result > 0) {
            socketPortList[i].serverSocket = result;
            socketPortList[i].portNumber = portNum;
            count++;
        } else {
            fprintf(stderr,"Failed to open TCP port %d for incoming connections, skipping (%d)\n",portNum,result);
            socketPortList[i].serverSocket = result;
            socketPortList[i].portNumber = -1;
        }
    }
    fprintf(stderr,"Opened %d server-side sockets\n",count);

    count = 0;
    for (i = 0; i < numSockets; i++) {
        int portNum = socketPortList[i].portNumber;
        if (portNum < 0)
            continue;
        int result = createClientSocket(portNum);
        if (result > 0) {
            socketPortList[i].clientSocket = result;
            socketPortList[i].connectedSocket = accept(socketPortList[i].serverSocket, NULL, 0);
            count++;
        } else {
            fprintf(stderr,"Failed to open TCP port %d for incoming connections, skipping (%d)\n",portNum,result);
            socketPortList[i].clientSocket = result;
        }
    }
    fprintf(stderr,"Connected %d client-side sockets\n",count);

    if (count > 0)
#ifdef __WIN32
        Sleep(sleepyTime * 1000); // Win32 Sleep() expects milliseconds
#else
        sleep(sleepyTime);
#endif
    appShutdown();

    return 0;
}
