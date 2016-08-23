#include <stdio.h>
#include <string.h>
#include <libgen.h>

int startsWith(char *str, char *prefix)
{
    if ((str != NULL) && (prefix != NULL))
        return strncmp(str,prefix,strlen(prefix)) == 0;
    else
        return 0;
}

int endsWith(char *str, char *suffix)
{
    if ((str != NULL) && (suffix != NULL)) {
        int prefixLen = strlen(str) - strlen(suffix);
        if (prefixLen >= 0)
            return strcmp(str + prefixLen,suffix) == 0;
    }
    return 0;
}

void simulateLsof(int count)
{
    int i;

    printf("p2655\ncdhclient\nLroot\nPUDP\nn*:68\nTQR=0\nTQS=0\n");
    printf("p2769\ncrpcbind\nLrpc\nPUDP\nn*:111\nTQR=0\nTQS=0\nPUDP\nn*:824\nTQR=0\nTQS=0\nPTCP\n");
    printf("n*:111\nTST=LISTEN\nTQR=0\nTQS=0\nPUDP\nn*:111\nTQR=0\nTQS=0\nPUDP\nn*:824\nTQR=0\nTQS=0\nPTCP\nn*:111\n");
    printf("TST=LISTEN\nTQR=0\nTQS=0\n");
    printf("p2790\ncrpc.statd\nLrpcuser\nPUDP\nn127.0.0.1:846\nTQR=0\nTQS=0\nPUDP\nn*:50953\nTQR=0\nTQS=0\nPTCP\nn*:39121\nTST=LISTEN\n");
    printf("TQR=0\nTQS=0\nPUDP\nn*:51727\nTQR=0\nTQS=0\nPTCP\nn*:54181\nTST=LISTEN\nTQR=0\nTQS=0\n");
    printf("p3062\ncsshd\nLroot\nPTCP\nn*:22\nTST=LISTEN\nTQR=0\nTQS=0\nPTCP\nn*:22\nTST=LISTEN\nTQR=0\nTQS=0\np3074\n");
    printf("csshd\nLroot\nPTCP\nn10.10.17.98:22->72.219.200.107:46284\nTST=ESTABLISHED\nTQR=0\nTQS=0\n");
    printf("p3091\ncntpd\nLntp\nPUDP\nn*:123\nTQR=0\nTQS=0\nPUDP\nn127.0.0.1:123\nTQR=0\nTQS=0\nPUDP\nn10.10.17.98:123\nTQR=0\nTQS=0\n");
    printf("p3111\ncsendmail\nLroot\nPTCP\nn127.0.0.1:25\nTST=LISTEN\nTQR=0\nTQS=0\n");
    printf("p3138\ncsshd\nLcore\nPTCP\nn10.10.17.98:22->72.219.200.107:46284\nTST=ESTABLISHED\nTQR=0\nTQS=0\n");
    for (i = 0; i < count; i++) {
        printf("p%d\ncsshd\nLcore\nPTCP\nn10.10.17.98:22->72.219.200.107:%d\nTST=ESTABLISHED\nTQR=0\nTQS=0\n",
               3140 + i * 2, 46286 + i * 2);
    }
}

void simulateNetstat(int count)
{
    int i;
    printf("\n");
    printf("Active Connections\n");
    printf("\n");
    printf("  Proto  Local Address          Foreign Address        State           PID\n");
    printf("  TCP    0.0.0.0:80             0.0.0.0:0              LISTENING       5268\n");
    printf("  TCP    0.0.0.0:135            0.0.0.0:0              LISTENING       964\n");
    printf("  TCP    0.0.0.0:443            0.0.0.0:0              LISTENING       5268\n");
    printf("  TCP    0.0.0.0:445            0.0.0.0:0              LISTENING       4\n");
    printf("  TCP    0.0.0.0:902            0.0.0.0:0              LISTENING       3584\n");
    printf("  TCP    0.0.0.0:912            0.0.0.0:0              LISTENING       3584\n");
    printf("  TCP    0.0.0.0:2809           0.0.0.0:0              LISTENING       304\n");
    printf("  TCP    0.0.0.0:2869           0.0.0.0:0              LISTENING       4\n");
    printf("  TCP    0.0.0.0:5357           0.0.0.0:0              LISTENING       4\n");
    printf("  TCP    0.0.0.0:5432           0.0.0.0:0              LISTENING       2400\n");
    printf("  TCP    0.0.0.0:6000           0.0.0.0:0              LISTENING       19816\n");
    printf("  TCP    0.0.0.0:8880           0.0.0.0:0              LISTENING       304\n");
    printf("  TCP    0.0.0.0:9043           0.0.0.0:0              LISTENING       304\n");
    printf("  TCP    0.0.0.0:9060           0.0.0.0:0              LISTENING       304\n");
    printf("  TCP    0.0.0.0:9080           0.0.0.0:0              LISTENING       304\n");
    printf("  TCP    0.0.0.0:9100           0.0.0.0:0              LISTENING       304\n");
    printf("  TCP    0.0.0.0:9443           0.0.0.0:0              LISTENING       304\n");
    printf("  TCP    0.0.0.0:49152          0.0.0.0:0              LISTENING       600\n");
    printf("  TCP    0.0.0.0:49153          0.0.0.0:0              LISTENING       852\n");
    printf("  TCP    0.0.0.0:49154          0.0.0.0:0              LISTENING       728\n");
    printf("  TCP    0.0.0.0:49155          0.0.0.0:0              LISTENING       1104\n");
    printf("  TCP    0.0.0.0:49158          0.0.0.0:0              LISTENING       2668\n");
    printf("  TCP    0.0.0.0:49171          0.0.0.0:0              LISTENING       720\n");
    printf("  TCP    0.0.0.0:59387          0.0.0.0:0              LISTENING       5268\n");
    printf("  TCP    127.0.0.1:5357         127.0.0.1:57817        TIME_WAIT       0\n");
    printf("  TCP    127.0.0.1:5357         127.0.0.1:57835        TIME_WAIT       0\n");
    printf("  TCP    127.0.0.1:6000         127.0.0.1:55873        ESTABLISHED     19816\n");
    printf("  TCP    127.0.0.1:6000         127.0.0.1:55874        ESTABLISHED     19816\n");
    printf("  TCP    127.0.0.1:6000         127.0.0.1:55875        ESTABLISHED     19816\n");
    for (i = 0; i < count; i++)
        printf("  TCP    127.0.0.1:6000         127.0.0.1:%-5d        ESTABLISHED     19816\n",55876 + i);
    printf("  TCP    127.0.0.1:9633         0.0.0.0:0              LISTENING       304\n");
    printf("  TCP    127.0.0.1:22000        0.0.0.0:0              LISTENING       2996\n");
    printf("  TCP    127.0.0.1:49165        127.0.0.1:49166        ESTABLISHED     304\n");
    printf("  TCP    127.0.0.1:49166        127.0.0.1:49165        ESTABLISHED     304\n");
    printf("  TCP    127.0.0.1:50484        127.0.0.1:50485        ESTABLISHED     11824\n");
    printf("  TCP    127.0.0.1:50485        127.0.0.1:50484        ESTABLISHED     11824\n");
    printf("  TCP    127.0.0.1:55873        127.0.0.1:6000         ESTABLISHED     19816\n");
    printf("  TCP    127.0.0.1:55874        127.0.0.1:6000         ESTABLISHED     19816\n");
    printf("  TCP    127.0.0.1:55875        127.0.0.1:6000         ESTABLISHED     19816\n");
    for (i = 0; i < count; i++)
        printf("  TCP    127.0.0.1:%-5d        127.0.0.1:6000         ESTABLISHED     19816\n",55876 + i);
    printf("  TCP    127.0.0.1:62522        0.0.0.0:0              LISTENING       1836\n");
    printf("  TCP    192.168.2.80:139       0.0.0.0:0              LISTENING       4\n");
    printf("  TCP    192.168.2.80:2869      192.168.2.1:1131       TIME_WAIT       0\n");
    printf("  TCP    192.168.2.80:5357      192.168.2.81:58833     TIME_WAIT       0\n");
    printf("  TCP    192.168.2.80:57752     157.56.53.43:12350     ESTABLISHED     5268\n");
    printf("  TCP    192.168.2.80:57754     65.55.223.37:40007     ESTABLISHED     5268\n");
    printf("  TCP    192.168.2.80:57755     31.13.69.197:443       ESTABLISHED     11824\n");
    printf("  TCP    192.168.2.80:57756     134.170.25.44:443      ESTABLISHED     5268\n");
    printf("  TCP    192.168.2.80:57757     31.13.69.197:443       ESTABLISHED     11824\n");
    printf("  TCP    192.168.2.80:57759     31.13.69.203:443       ESTABLISHED     11824\n");
    printf("  TCP    192.168.2.80:57761     23.192.160.17:80       ESTABLISHED     11824\n");
    printf("  TCP    192.168.2.80:57766     192.168.2.1:1780       TIME_WAIT       0\n");
    printf("  TCP    192.168.2.80:57767     137.135.101.1:443      ESTABLISHED     5268\n");
    printf("  TCP    192.168.2.80:57769     12.152.56.162:22       TIME_WAIT       0\n");
    printf("  TCP    192.168.2.80:57805     192.168.2.1:1780       TIME_WAIT       0\n");
    printf("  TCP    192.168.2.80:57819     192.168.2.1:1780       TIME_WAIT       0\n");
    printf("  TCP    192.168.2.80:57820     91.190.216.25:12350    TIME_WAIT       0\n");
    printf("  TCP    192.168.2.80:57821     192.168.2.40:3911      TIME_WAIT       0\n");
    printf("  TCP    192.168.2.80:57822     192.168.2.1:1780       TIME_WAIT       0\n");
    printf("  TCP    192.168.2.80:57823     192.168.2.1:1780       TIME_WAIT       0\n");
    printf("  TCP    192.168.2.80:57827     192.168.2.1:1780       TIME_WAIT       0\n");
    printf("  TCP    192.168.2.80:57831     64.12.104.85:443       ESTABLISHED     19124\n");
    printf("  TCP    192.168.2.80:57833     64.12.104.69:443       ESTABLISHED     19124\n");
    printf("  TCP    192.168.2.80:57834     64.12.27.69:443        ESTABLISHED     19124\n");
    printf("  TCP    192.168.2.80:57836     173.194.206.125:5222   ESTABLISHED     19124\n");
    printf("  TCP    192.168.2.80:57840     23.15.7.96:80          ESTABLISHED     1948\n");
    printf("  TCP    192.168.2.80:57843     23.15.7.96:80          ESTABLISHED     1948\n");
    printf("  TCP    192.168.2.80:57844     23.6.72.154:80         ESTABLISHED     1948\n");
    printf("  TCP    192.168.66.1:139       0.0.0.0:0              LISTENING       4\n");
    printf("  TCP    192.168.88.1:139       0.0.0.0:0              LISTENING       4\n");
    printf("  TCP    [::]:135               [::]:0                 LISTENING       964\n");
    printf("  TCP    [::]:445               [::]:0                 LISTENING       4\n");
    printf("  TCP    [::]:2809              [::]:0                 LISTENING       304\n");
    printf("  TCP    [::]:2869              [::]:0                 LISTENING       4\n");
    printf("  TCP    [::]:3587              [::]:0                 LISTENING       5300\n");
    printf("  TCP    [::]:5357              [::]:0                 LISTENING       4\n");
    printf("  TCP    [::]:5432              [::]:0                 LISTENING       2400\n");
    printf("  TCP    [::]:8880              [::]:0                 LISTENING       304\n");
    printf("  TCP    [::]:9043              [::]:0                 LISTENING       304\n");
    printf("  TCP    [::]:9060              [::]:0                 LISTENING       304\n");
    printf("  TCP    [::]:9080              [::]:0                 LISTENING       304\n");
    printf("  TCP    [::]:9100              [::]:0                 LISTENING       304\n");
    printf("  TCP    [::]:9443              [::]:0                 LISTENING       304\n");
    printf("  TCP    [::]:49152             [::]:0                 LISTENING       600\n");
    printf("  TCP    [::]:49153             [::]:0                 LISTENING       852\n");
    printf("  TCP    [::]:49154             [::]:0                 LISTENING       728\n");
    printf("  TCP    [::]:49155             [::]:0                 LISTENING       1104\n");
    printf("  TCP    [::]:49158             [::]:0                 LISTENING       2668\n");
    printf("  TCP    [::]:49171             [::]:0                 LISTENING       720\n");
    printf("  TCP    [fe80::705b:9b48:788b:4f52%12]:5357  [fe80::61b2:2fca:7e08:5732%12]:58831  TIME_WAIT       0\n");
    printf("  UDP    0.0.0.0:443            *:*                                    5268\n");
    printf("  UDP    0.0.0.0:500            *:*                                    1104\n");
    printf("  UDP    0.0.0.0:1434           *:*                                    3024\n");
    printf("  UDP    0.0.0.0:3702           *:*                                    1072\n");
    printf("  UDP    0.0.0.0:3702           *:*                                    1464\n");
    printf("  UDP    0.0.0.0:3702           *:*                                    1072\n");
    printf("  UDP    0.0.0.0:3702           *:*                                    1464\n");
    printf("  UDP    0.0.0.0:4500           *:*                                    1104\n");
    printf("  UDP    0.0.0.0:5355           *:*                                    1948\n");
    printf("  UDP    0.0.0.0:54567          *:*                                    1360\n");
    printf("  UDP    0.0.0.0:54897          *:*                                    1072\n");
    printf("  UDP    0.0.0.0:56492          *:*                                    11824\n");
    printf("  UDP    0.0.0.0:57307          *:*                                    1464\n");
    printf("  UDP    0.0.0.0:58227          *:*                                    1072\n");
    printf("  UDP    0.0.0.0:59387          *:*                                    5268\n");
    printf("  UDP    127.0.0.1:1900         *:*                                    1464\n");
    printf("  UDP    127.0.0.1:49230        *:*                                    1948\n");
    printf("  UDP    127.0.0.1:51388        *:*                                    1464\n");
    printf("  UDP    127.0.0.1:52320        *:*                                    19124\n");
    printf("  UDP    127.0.0.1:52321        *:*                                    19124\n");
    printf("  UDP    127.0.0.1:55548        *:*                                    19124\n");
    printf("  UDP    127.0.0.1:55549        *:*                                    19124\n");
    printf("  UDP    127.0.0.1:55570        *:*                                    19124\n");
    printf("  UDP    127.0.0.1:55571        *:*                                    19124\n");
    printf("  UDP    127.0.0.1:55576        *:*                                    19124\n");
    printf("  UDP    127.0.0.1:55577        *:*                                    19124\n");
    printf("  UDP    127.0.0.1:59032        *:*                                    5260\n");
    printf("  UDP    127.0.0.1:65100        *:*                                    5268\n");
    printf("  UDP    127.0.0.1:65101        *:*                                    5268\n");
    printf("  UDP    192.168.2.80:137       *:*                                    4\n");
    printf("  UDP    192.168.2.80:138       *:*                                    4\n");
    printf("  UDP    192.168.2.80:1900      *:*                                    1464\n");
    printf("  UDP    192.168.2.80:51385     *:*                                    1464\n");
    printf("  UDP    192.168.66.1:137       *:*                                    4\n");
    printf("  UDP    192.168.66.1:138       *:*                                    4\n");
    printf("  UDP    192.168.66.1:1900      *:*                                    1464\n");
    printf("  UDP    192.168.66.1:51386     *:*                                    1464\n");
    printf("  UDP    192.168.88.1:137       *:*                                    4\n");
    printf("  UDP    192.168.88.1:138       *:*                                    4\n");
    printf("  UDP    192.168.88.1:1900      *:*                                    1464\n");
    printf("  UDP    192.168.88.1:51387     *:*                                    1464\n");
    printf("  UDP    [::]:500               *:*                                    1104\n");
    printf("  UDP    [::]:1434              *:*                                    3024\n");
    printf("  UDP    [::]:3540              *:*                                    5300\n");
    printf("  UDP    [::]:3702              *:*                                    1072\n");
    printf("  UDP    [::]:3702              *:*                                    1464\n");
    printf("  UDP    [::]:3702              *:*                                    1072\n");
    printf("  UDP    [::]:3702              *:*                                    1464\n");
    printf("  UDP    [::]:4500              *:*                                    1104\n");
    printf("  UDP    [::]:5355              *:*                                    1948\n");
    printf("  UDP    [::]:51122             *:*                                    1360\n");
    printf("  UDP    [::]:54898             *:*                                    1072\n");
    printf("  UDP    [::]:56493             *:*                                    11824\n");
    printf("  UDP    [::]:57308             *:*                                    1464\n");
    printf("  UDP    [::]:58228             *:*                                    1072\n");
    printf("  UDP    [::1]:1900             *:*                                    1464\n");
    printf("  UDP    [::1]:49232            *:*                                    2400\n");
    printf("  UDP    [::1]:51384            *:*                                    1464\n");
    printf("  UDP    [fe80::1dd8:a2ce:c114:df54%17]:1900  *:*                                    1464\n");
    printf("  UDP    [fe80::1dd8:a2ce:c114:df54%17]:51383  *:*                                    1464\n");
    printf("  UDP    [fe80::45d1:dc12:6805:7726%16]:1900  *:*                                    1464\n");
    printf("  UDP    [fe80::45d1:dc12:6805:7726%16]:51382  *:*                                    1464\n");
    printf("  UDP    [fe80::705b:9b48:788b:4f52%12]:546  *:*                                    852\n");
    printf("  UDP    [fe80::705b:9b48:788b:4f52%12]:1900  *:*                                    1464\n");
    printf("  UDP    [fe80::705b:9b48:788b:4f52%12]:51381  *:*                                    1464\n");
}

int main(int argc, char **argv)
{
    char *progname = basename(argv[0]);

    // printf("progname=%s\n",basename(progname));
    if (startsWith(progname,"lsof")) {
        simulateLsof(1000);
    } else if (startsWith(progname,"netstat")) {
        simulateNetstat(1000);
    } else {
        printf("Unrecognized program name: %s\n",progname);
    }
    return 0;
}
