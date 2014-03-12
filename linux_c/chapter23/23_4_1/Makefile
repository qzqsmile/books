main: main.o  alloc_unit.o 
	gcc main.o ret_allocator.o -o main
main.o: main.c ret_allocator.h
	gcc -c main.c
alloc_unit.o:ret_allocator.c ret_allocator.h
	gcc -c ret_allocator.c

clean:
	@echo "cleaning"
	-rm *.o
	@echo "clean compeleted"
