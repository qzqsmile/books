main: main.o ret_ptr.o ret_ptr.h
	g++ main.o ret_ptr.o -o main
main.o:main.c ret_ptr.h
	g++ -c main.c
ret_ptr.o:ret_ptr.c ret_ptr.h
	g++ -c ret_ptr.c

clean:
	@echo "clean project"
	-rm *.o
	@echo "clean compeleted"
