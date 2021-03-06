#include<iostream>
#include<cstring>
#include<algorithm>
#include"Vec"

class Str {
		friend std::istream& operator>> (std::istream&, Str&);
	public:
		operator double() const;
		operator char*();
		operator const char*() const;
		Str& operator+=(const Str& s){
			std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
			return *this;
		}
		typedef Vec<char> :: size_type size_type;
		Str() { }
		Str(size_type n, char c) : data(n, c) { }
		Str(const char* cp){
			std::copy(cp, cp+std::strlen(cp), std::back_inserter(data));
		}

		template<class In> Str(In b, In e){
			std::copy(b, e, std::back_inserter(data));
		}

		char& operator[] (size_type i) {return data[i];}
		const char& operator[](size_type i)const { return data[i]; }
	private:
		Vec<char> data;
};

std::istream & operator>>(std::istream&, Str&);
std::ostream & operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);

Str operator+(const Str& s, const Str& t)
{
	Str r = s;
	r += t;
	return r;
}

std::istream& operator>>(std::istream& is, Str& s)
{
	s.data.clear();
	char c;
	while(is.get(c) && isspace(c))
		;

	if(is){
		do s.data.push_back(c);
		while(is.get(c) && !isspace(c));

		if(is)
			is.unget();
	}

	return is;
}

int main()
{
	return 0;
}
