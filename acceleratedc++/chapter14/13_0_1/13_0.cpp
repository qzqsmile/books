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
using std::runtime_error;
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
		virtual Core* clone() const { return new Core(*this);}
	protected:
		//virtual Core* clone() const { return new Core(*this);}
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
	private:
		double thesis;
};

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

istream& Grad::read(istream& in)
{
	Core::read_common(in);
	in >> thesis;
	::read_hw(in, Core::homework);
	return in;
}

double Grad::grade() const
{
	return min(Core::grade(), thesis);
}

bool compare(const Core& c1, const Core& c2)
{
	return c1.name() < c2.name();
}

template<class T> class Handle {
	public:
		Handle():p(0) {}
		Handle(const Handle& s):p(0) {if (s.p) p = s.p->clone();}
		Handle& operator=(const Handle&);
		~Handle() { delete p;}

		Handle(T *t):p(t) { }

		operator bool() const { return p;}
		T& operator*() const;
		T* operator->() const;

	private:
		T* p;
};

template<class T>
T& Handle<T> :: operator*() const
{
	if(p)
		return *p;
	throw runtime_error("unbound Handle");
}

bool compare_Core_handles(const Handle<Core>& cp1, const Handle<Core>& cp2)
{
	return compare(*cp1, *cp2);
}

template <class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs)
{
	if (&rhs != this){
		delete p;
		p = rhs.p ? rhs.p->clone() : 0;
	}

	return *this;
}

template<class T>
T* Handle<T>::operator->() const
{
	if(p)
		return p;
	throw runtime_error("unbound Handle");
}

class Student_info{
	public:
		Student_info(){ }
		Student_info(std::istream& is){ read(is);}

		std::istream& read(std::istream&);
		std::string name() const{
			if (cp) return cp->name();
			else throw std::runtime_error("uninitialized Student");
		}
		double grade() const {
			if (cp) return cp->grade();
			else throw std::runtime_error("uninitialized Student");
		}
		static bool compare(const Student_info& s1, const Student_info& s2){
			return s1.name() < s2.name();
		}
	private:
		Handle<Core> cp;
};

istream& Student_info::read(istream& is)
{
	char ch;
	is >> ch;

	if (cp == 'U')
		cp = new Core(is);
	else
		cp = new Grad(is);

	return is;
}

template <class T> class Ref_handle{
	public:
		Ref_handle():p(0),refptr(new std::size_t(1)) { }
		Ref_handle(T* t): p(t), refptr(new std::size_t(1)){ }
		Ref_handle(const Ref_handle& h):p(h.p), refptr(h.refptr){
			++*refptr;
		}
		Ref_handle& operator=(const Ref_handle&);
		~Ref_handle();

		operator bool() const{ return p;}
		T& operator*() const{
			if (p)
				return *p;
			throw runtime_error("unbound Ref_handle");
		}
		T* operator->() const{
			if (p)
				return p;
			throw runtime_error("unbound Ref_handle");
		}
	private:
		T* p;
		std::size_t* refptr;
};


template <class T> 
Ref_handle<T>& Ref_handle<T> :: operator= (const Ref_handle& rhs) 
{
	++*rhs.refptr;
	if (--*refptr == 0){
		delete refptr;
		delete p;
	}
	refptr = rhs.refptr;
	p = rhs.p;
	return *this;
}

bool compare_Ref_handle(const Ref_handle<Core>& cp1, const Ref_handle<Core>& cp2)
{
	return compare(*cp1, *cp2);
}

template<class T> Ref_handle<T>::~Ref_handle()
{
	if (--*refptr == 0){
		delete refptr;
		delete p;
	}
}

int main()
{
	vector<Ref_handle<Core> >students;
	Ref_handle<Core> record;
	char ch;
	string::size_type maxlen = 0;	

	while(cin >> ch){
		if (ch == 'U')
			record = new Core;
		else
			record = new Grad;
		record->read(cin);
		maxlen = max(maxlen, record->name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare_Ref_handle);
	
	for (vector<Handle<Core> >::size_type i = 0; i != students.size(); ++i){
		cout << students[i]->name() << string (maxlen + 1 - students[i]->name().size(),' ');
		try{
			double final_grade = students[i]->grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade 
				<< setprecision(prec) << endl;
		}catch(domain_error e){
			cout << e.what() << endl;
		}
	}

	return 0;
}
