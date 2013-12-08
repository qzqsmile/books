#include<iostream>
#include<iomanip>
#include<ios>
#include<vector>
#include<algorithm>
#include<stdexcept>
#include<string>
#include"Student_info.h"

using std::string;
using std::cout;
using std::sort;
using std::vector;
using std::endl;
using std::domain_error;
using std::istream;
using std::max;
using std::cin;
using std::setprecision;
using std::streamsize;

int main()
{
	vector<Student_info> students;
	vector<Student_info> pass_students, fail_students;
	Student_info record;
	string::size_type maxlen = 0;

	while(record.read(cin)){
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for (vector<Student_info> :: size_type i = 0; i != students.size(); ++i){
		cout << students[i].name() << string(maxlen + 1 - students[i].name().size(),' ');
		try{
			double final_grade = students[i].grade(); 
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		}catch (domain_error e){
			cout << e.what() << endl;
		}
	}

	for(vector<Student_info> :: size_type i = 0; i != students.size(); i++)
	{
		if (students[i].is_pass()){
			pass_students.push_back(students[i]);
		}
		else{
			fail_students.push_back(students[i]);
		}
	}
	
	cout << "The pass students is:" << endl;

	for (vector<Student_info> :: size_type i = 0; i != pass_students.size(); ++i){
		cout << pass_students[i].name() << string(maxlen + 1 - pass_students[i].name().size(),' ');
	}
	cout << endl;

	cout << "The false students is:" << endl;
	for (vector<Student_info> :: size_type i = 0; i != fail_students.size(); ++i){
		cout << fail_students[i].name() << string(maxlen + 1 - fail_students[i].name().size(),' ');
		}

	cout << endl;
	return 0;
}
