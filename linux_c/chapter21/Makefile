#main: main.o stack.o maze.o
#	gcc main.o stack.o maze.o -o main
#main.o: main.c main.h stack.h maze.h
#	gcc -c main.c
#stack.o: stack.c stack.h main.h
#	gcc -c stack.c
#maze.o: maze.c maze.h main.h   
#	gcc -c maze.c
#
#clean:
#	@echo "cleanning project"
#	-rm main *.o
#	@echo "clean completed"
#
#PHONY: clean

#main: main.o stack.o maze.o
#	gcc main.o stack.o maze.o -o main
#
#main.o: main.h stack.h maze.h
#stack.o: stack.h main.h
#maze.o: maze.h main.h

#main.o: main.c
#	gcc main.c -c
#stack.o: stack.c
#	gcc stack.c -c 
#maze.o: maze.c
#	gcc maze.c -c

#clean:
#	-rm main *.o
#
#.PHONY: clean

#main: main.o stack.o maze.o
#	gcc $^ -o $@
#main.o stack.o maze.o: main.h
#main.o maze.o: maze.h
#main.o stack.o:stack.h
#
#clean:
#	-rm main *.o
#
#.PHONY: clean

all:main

main: main.o stack.o maze.o
	gcc $^ -o $@
clean: 
	-rm main *.o *.d
.PHONY: clean

OBJS = main.o stack.o maze.o

-include $(OBJS:.o =.d)

%.o: %.c
	gcc -c $(CFLAGS) $*.c -o $*.o
	gcc -MM $(CPPFLAGS) $*.c > $*.d
	mv -f $*.d $*.d.tmp
	sed -e 's|.*:|$*.o:|' < $*.d.tmp > $*.d
	sed -e 's/.*://' -e 's/\\$$//' < $*.d.tmp | fmt -1 | \
	sed -e 's/^ *//' -e 's/$$/:/' >> $*.d
	rm -f $*.d.tmp
