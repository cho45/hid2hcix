

.PHONY: all mac win clean

mac:
	make -f ./Makefile.mac

win:
	make -f ./Makefile.mingw

all: mac win


clean:
	make -f ./Makefile.mac clean
	make -f ./Makefile.mingw clean
