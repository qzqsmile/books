#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<string>

using std::cin;
using std::sort;
using std::max;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::setprecision;
using std::streamsize;

class Student_info
{
    private:
	double midterm, final;
	string  n;
    public:
	string if_pass();
	std::istream &read(std::istream &is);
	string name() const { return n;};
	double grade() const;
};

double Student_info :: grade() const
{
    return (midterm + final) / 2;
}

string Student_info :: if_pass()
{
    double result_grade = (midterm + final) / 2;

    if (result_grade >= 60){
	return "P";
    }
    return "F";
}

std::istream& Student_info::read(std::istream& in) 
{
    in >> n >> midterm >> final;
    
    return in;
}

int main()
{
    string :: size_type maxlen;
    Student_info record;
    vector<Student_info> students;
    
    while (record.read(cin)){
	record.if_pass();
	maxlen = max(maxlen, record.name().size());
	students.push_back(record);
    }

    for (vector<Student_info> :: size_type i = 0; i != students.size(); i++){
	double final_grade = students[i].grade();
	cout << students[i].name() << string(maxlen + 1 - students[i].name().size(),' ');
	streamsize prec = cout.precision();
	cout << setprecision(3) << final_grade << setprecision(prec);
	cout << " "<< students[i].if_pass() << endl;
    }

    return 0;
}
