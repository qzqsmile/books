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

string letter_grade(double grade);

int main()
{
	vector<Student_info> students;
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
			string final_letter = letter_grade(final_grade);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << " "<< final_letter << endl;
		}catch (domain_error e){
			cout << e.what() << endl;
		}
	}
	
	return 0;
}

string letter_grade(double grade)
{
	static const double numbers[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
	};
	static const char* const letters[] = {
		"A+","A","A-","B+","B","B-","C    +","C","C-","D","F"
	};
	static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);

	for (size_t i = 0; i < ngrades; ++i){
		if(grade >= numbers[i])
			return letters[i];
	}

	return "?\?\?";
}

