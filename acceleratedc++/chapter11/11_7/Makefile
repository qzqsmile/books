main: 11_7.o grade.o median.o Student_info.o
	g++ 11_7.o grade.o median.o Student_info.o -o main	 
11_7.o: Student_info.h 11_7.cpp Vec
	g++ -c 11_7.cpp
grade.o: grade.cpp grade.h median.h Student_info.h Vec
	g++ -c grade.cpp
median.o: median.cpp 
	g++ -c median.cpp
Student_info.o: Student_info.cpp Student_info.h grade.h Vec
	g++ -c Student_info.cpp

clean:
	@echo "cleanning porject"
	-rm *.o main
	@echo "clean completed"
