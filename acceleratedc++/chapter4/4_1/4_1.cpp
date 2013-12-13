#include<algorithm>
#include<iostream>
#include<string>
#include<ios>
#include<iomanip>
#include<vector>
#include<stdexcept>
#include"grade.h"
#include"Student_info.h"

using std::cout;
using std::cin;
using std::streamsize;
using std::domain_error;
using std::setprecision;
using std::sort;
using std::string;
using std::vector;
using std::max;
using std::endl;

int  main()
{
	vector<Student_info> students;
	Student_info record;
	string :: size_type maxlen = 0;

//    example
//    int maxlen;
//    Student_info s;
//    max(s.name.size(), maxlen);
//
	while(read(cin, record)){
		maxlen = max(record.name.size(),maxlen);
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for(vector<Student_info>::size_type i = 0; i != students.size(); ++i){
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(),' ');

		try{
			double final_grade = grade(students[i]); 
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec);
		}catch (domain_error e){
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}
