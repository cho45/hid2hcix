

.PHONY: all clean

all:
	make -f ./Makefile.mac
	make -f ./Makefile.mingw

clean:
	make -f ./Makefile.mac clean
	make -f ./Makefile.mingw clean
