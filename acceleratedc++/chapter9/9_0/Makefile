main: 9_0.o grade.o median.o Student_info.o
	g++ 9_0.o grade.o median.o Student_info.o -o main	 
9_0.o: Student_info.h 9_0.cpp 
	g++ -c 9_0.cpp
grade.o: grade.cpp grade.h median.h Student_info.h
	g++ -c grade.cpp
median.o: median.cpp 
	g++ -c median.cpp
Student_info.o: Student_info.cpp Student_info.h grade.h
	g++ -c Student_info.cpp

clean:
	@echo "cleanning porject"
	-rm *.o
	@echo "clean completed"

