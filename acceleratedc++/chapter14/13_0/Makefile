main:13_0.o grade.o median.o
	g++ 13_0.o grade.o median.o -o main
13_0.o:13_0.cpp grade.h
	g++ -c 13_0.cpp
grade.o:grade.cpp median.h grade.h
	g++ -c grade.cpp
median.o: median.cpp  
	g++ -c median.cpp

clean:
	@echo "cleaning project"
	-rm *.o
	@echo "clean completed"
