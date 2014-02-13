#ifndef GUARD_grade_h
#define GUARD_grade_h

#include<vector>
#include"Student_info.h"
#include"Vec"

using std::vector;

double grade(double, double, double);
double grade(double, double, const Vec<double>&);
double garde(const Student_info&);

#endif
