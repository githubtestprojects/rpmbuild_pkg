all: foo

foo:
	gcc -Wall -g -c -fPIC config.c
	gcc -Wall -g -c -fPIC logging.c
	gcc -shared config.o logging.o -o ../../lib/libfacilities.so

clean:
	rm -f *.o

install:
	install -m 0755 -d $(ROOT)$(INCLUDEDIR)/facilities
	install -m 0755 *.h $(ROOT)$(INCLUDEDIR)/facilities

dist: clean
