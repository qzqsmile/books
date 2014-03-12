#all: main
#
#main:para_callback.o main.o para_callback.h
#	gcc $^ -o $@
#
#main.o: main.c para_callback.h
#para_callback.o:para_callback.c para_callback.h
#
#clean:
#	-rm main *.o
#
#
#.PHONY: clean
#

all: main

main:generics.o main1.o
	g++ $^ -o $@

generics.o:generics.h
main1.o:generics.h

clean:
	-rm main *.o

.PHONY: clean
