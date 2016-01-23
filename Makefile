INSTALL=/lib

CFLAGS+= -Wall
LDFLAGS+= -lc -ldl -lutil

all: antidebug.so

antidebug.so: anti.c
 $(CC) -fPIC -g -c anti.c
 $(CC) -fPIC -ldl -shared -Wl,-soname,antidebug.so anti.o -o antidebug.so

install: all
 @test -d $(INSTALL) || mkdir $(INSTALL)
 @install -m 0755 antidebug.so $(INSTALL)/
 @echo [+] Installing anti-debug hook...
 @echo $(INSTALL)/antidebug.so > /etc/ld.so.preload
 @echo [!] Installed.
clean:
 rm *.so *.o
