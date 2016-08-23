#
#
#

linux: ../bin/fake_load

windows: ../bin/fake_load.exe

all: linux windows

../bin:
	mkdir -p ../bin

../bin/fake_load: fake_load.c ../bin
	gcc -o $@ $<
	cp $@ ../bin/netstat
	cp $@ ../bin/lsof

clean:
	rm -rf ../bin

../bin/fake_load.exe: fake_load.c ../bin
	i686-pc-mingw32-gcc -o $@ $<
	cp $@ ../bin/netstat.exe
