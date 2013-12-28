#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<iomanip>
#include<stdexcept>
#include<ios>
#include<algorithm>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::map;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::istream;

struct Student_info {
	std::string name;
	double midterm, final, grade;	
	std::vector < double >homework;
};
bool compare(const Student_info &, const Student_info &);
std::istream & read(std::istream &, Student_info  &);
std::istream & read_hw(std::istream &, std::vector < double >&);
double grade(double, double, double);
double grade(double, double, const std::vector < double >&);
double grade(const Student_info &);
double median(std::vector < double >);
void sort_grade(map <string, vector<Student_info> > & sort_students, vector<Student_info> & students);
void print_students_rank( map<string, vector<Student_info> >& sort_students);

int main()
{
	vector <Student_info> students;
    map <string, vector<Student_info> > sort_students;
	Student_info record;
	string::size_type maxlen = 0;
	map<string, vector<string> > sort_rule;

	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);
	for (vector < Student_info >::size_type i = 0; i != students.size(); ++i) { 
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' '); 
		try {
			double final_grade = grade(students[i]);
            students[i].grade = final_grade;
			streamsize prec = cout.precision();

			cout << setprecision(3) << final_grade <<
			    setprecision(prec);
		} catch(domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
    sort_grade(sort_students, students);
    print_students_rank(sort_students);

	return 0;
}

bool compare(const Student_info & x, const Student_info & y)
{
	return x.name < y.name;
}

istream & read(istream & is, Student_info & s)
{
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);

	return is;
}

istream & read_hw(istream & in, vector < double >&hw)
{
	if (in) {
		hw.clear();

		double x;
		while (in >> x)
			hw.push_back(x);

		in.clear();
	}

	return in;
}

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const std::vector < double >&hw)
{
	if (hw.size() == 0)
		throw domain_error("Student has done no homework");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info & s)
{
	return grade(s.midterm, s.final, s.homework);
}

double median(std::vector < double >vec)
{
	typedef vector < double >::size_type vec_sz;

	vec_sz size = vec.size();
	if (0 == size)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());

	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

void sort_grade(map <string, vector<Student_info> > & sort_students, vector<Student_info> & students)
{
    for (vector<Student_info> :: const_iterator iter = students.begin(); iter != students.end(); iter++){
        switch ((int)(iter->grade) / 10)
        {
            case 9:
                sort_students["A"].push_back(*iter);
                break;
            case 8:
                sort_students["B"].push_back(*iter);
                break;
            case 7:
                sort_students["C"].push_back(*iter);
                break;
            case 6:
                sort_students["D"].push_back(*iter);
                break;
            case 5: 
            case 4: 
            case 3: 
            case 2: 
            case 1: 
                sort_students["F"].push_back(*iter);
                break;
            default:
                cout << "The grade number is beyound"<<endl;
                break;
        }

   }
}

void print_students_rank( map<string, vector<Student_info> >& sort_students)
{
    cout << "The rank A(90-100)" <<sort_students["A"].size() << endl;
    cout << "The rank B(80-90)" << sort_students["B"].size() << endl;
    cout << "The rank C(70-80)" << sort_students["C"].size() << endl;
    cout << "The rank D(60-70)" << sort_students["D"].size() << endl;
    cout << "The rank F(<60)" << sort_students["F"].size() << endl;
}
