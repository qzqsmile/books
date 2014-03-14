#include<string>
#include<vector>
#include<stdexcept>
#include<ios>
#include<iomanip>
#include<algorithm>
#include<iostream>
#include"grade.h"

using std::min;
using std::vector;
using std::istream;
using std::string;
using std::sort;
using std::cout;
using std::cin;
using std::endl;
using std::max;
using std::streamsize;
using std::domain_error;
using std::setprecision;

class Core{
	friend class Student_info;
	public: 
		//default constructor for Core
		virtual ~Core() { }
		Core(): midterm(0), final(0){}
		Core(std::istream& is) {read(is);}
		std::string name () const;
		virtual	std::istream& read (std::istream&);
		virtual	double grade() const;
		bool valid() const { return !homework.empty();}
		virtual	bool predicate() const;
	protected:
		virtual Core* clone() const { return new Core(*this);}
		std::istream& read_common(std::istream&);
		double midterm, final;
		std::vector<double> homework;
	private:
		std::string n;
};

class Grad: public Core{
	public:
		Grad():thesis(0){ }
		std::istream& read(std::istream&);
		Grad(std::istream& is){read(is);}
		double grade() const;
		bool predicate() const;
	private:
		double thesis;
};

class Student_info{
	public:
		Student_info():cp(0){ }
		Student_info(std::istream& is):cp(0) { read(is);}
		Student_info(const Student_info&);
		Student_info& operator=(const Student_info&);
		~Student_info() {delete cp;}

		std::istream& read(std::istream&);

		std::string name() const{
			if (cp) return cp->name();
			else throw std::runtime_error("uninitialized Students");
		}

		double grade() const {
			if (cp) return cp->grade();
			else throw std::runtime_error("uninitialized Student");
		}
		static bool compare(const Student_info& s1, const Student_info& s2){
			return s1.name() < s2.name();
		}
	private:
		Core* cp;
};

istream& Student_info::read(istream& is)
{
	delete cp;

	char ch;
	is >> ch;

	if (ch == 'U'){
		cp = new Core(is);
	}else{
		cp = new Grad(is);
	}

	return is;
}

Student_info::Student_info(const Student_info& s)
{
	if (s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s)
{
	if (&s != this){
		delete cp;
		if (s.cp)
			cp = s.cp->clone();
		else
			cp = 0;
	}

	return *this;
}

string Core::name() const {return n;}

double Core::grade() const
{
	return ::grade(midterm, final, homework);
}

istream& Core::read_common(istream& in)
{
	in >> n >> midterm >> final;
	return in;
}

std::istream& read_hw(std::istream& in, vector<double>& hw)
{
	if (in){
		hw.clear();

		double x;
		while (in >> x)
			hw.push_back(x);

		in.clear();
	}
	return in;
}

istream& Core::read(istream& in)
{
	read_common(in);
	::read_hw(in, homework);
	return in;
}

bool Core::predicate() const
{
	if(!valid())
		return false;
}

istream& Grad::read(istream& in)
{
	Core::read_common(in);
	in >> thesis;
	::read_hw(in, Core::homework);
	return in;
}

bool Grad::predicate() const
{
	if(valid())
		if(thesis)
			return true;
	return false;
}
double Grad::grade() const
{
	return min(Core::grade(), thesis);
}

bool compare(const Core& c1, const Core& c2)
{
	return c1.name() < c2.name();
}

bool compare_Core_ptrs(const Core* cp1, const Core* cp2)
{
	return compare(*cp1, *cp2);
}

int main(void)
{
	//version 1
//	vector<Core*> students;
//	Core* record;
//	char ch;
//	string :: size_type maxlen = 0;
//
//	while (cin >> ch){
//		if (ch == 'U')
//			record = new Core;
//		else 
//			record = new Grad;
//		record->read(cin);
//		maxlen = max(maxlen, record->name().size());
//		students.push_back(record);
//	}
//
//	sort(students.begin(), students.end(), compare_Core_ptrs);
//
//	for (vector<Core*>::size_type i = 0;
//			i != students.size(); i++){
//		cout << students[i]->name()
//			<< string(maxlen + 1 - students[i]->name().size(),' ');
//		try{
//			double final_grade = students[i]->grade();
//			streamsize prec = cout.precision();
//			cout << setprecision(3) << final_grade 
//				<< setprecision(prec) << endl;
//		}catch (domain_error e){
//			cout << e.what() << endl;
//		}
//		delete students[i];
//	}

	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	//read and store the data

	while(record.read(cin)){
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}
	Grad s;

	sort(students.begin(), students.end(), Student_info::compare);

	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i){
		cout << students[i].name() << string(maxlen + 1 -students[i].name().size(), ' ');
		try{
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}catch(domain_error e){
			cout << e.what() << endl;
		}
	}

	return 0;
}
