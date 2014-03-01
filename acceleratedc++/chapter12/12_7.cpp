#include<iostream>
#include<algorithm>
#include<cstring>
#include<memory>
#include<algorithm>
#include"Vec"

using std::copy;

class Str {
		friend std::istream& operator>> (std::istream&, Str&);
	public:
		typedef char* iterator;
		operator double() const;
		operator char*();
		operator const char*() const;
		Str& operator+=(const Str& s){
			std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
			return *this;
		}
		typedef Vec<char> :: size_type size_type;
		const char* c_str() const;
		const char* c_data() const;

		Str() {create(0 , '\0');}
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
		iterator begin;
		iterator end;
		size_type length;

		allocator<char> alloc;
		void create(size_type, char);
		size_t copy (char* s, size_t len, size_t pos) const;

		template<class In> void create (In, In);
		void uncreate();
		void grow(size_type);
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
	while(is.get(c) && isspace(c));

	if(is){
		do s.data.push_back(c);
		while(is.get(c) && !isspace(c));

		if(is)
			is.unget();
	}

	return is;
}

void Str :: create(size_type n, char val)
{
	length = n + 1;
	begin = alloc.allocate(length);
	end = begin + length - 1;
	uninitialized_fill(begin, begin + length - 1, val);
	alloc.construct(begin + length - 1, '\0');
}

template<class In> void  Str :: create (In i, In j)
{
	length = j - i + 1;
	begin = alloc.allocate(length);
	end = begin + length - 1;
	uninitialized_copy(i, j, begin);
	alloc.construct(begin + length - 1, '\0');
}

void Str :: uncreate()
{
	if (begin) {
		iterator it = begin  + length;
		while (it != begin) alloc.destroy(--it);
		alloc.deallocate(begin, length);
	}

	begin =  end = 0;
	length = 0;
}

const char* Str :: c_str() const
{
	static char str[100];
	for (int i = 0; i != length; i++){
		str[i] = *(begin + i);
	}
	str[length] = '\0';
	return str;
}

const char* Str :: c_data() const
{
	return begin;
}

size_t Str :: copy (char* s, size_t len, size_t pos = 0) const
{
	size_t copy_length;
	copy_length = std::min(len, (length - pos));
	::copy(begin + pos, begin + copy_length, s);
	return copy_length;
}


bool operator== (const Str& lhs, const Str& rhs)
{
	if (0 == strcmp(lhs.c_str(), rhs.c_str()))
		return 1;
	return 0;
}

bool operator!= (const Str& lhs, const Str& rhs)
{
	if (0 != strcmp(lhs.c_str(), rhs.c_str()))
		return 1;
	return 0;
}

bool operator< (const Str& lhs, const Str& rhs)
{
	if (strcmp(lhs.c_str(), rhs.c_str()) < 0)
		return 1;
	return 0;
}

bool operator<= (const Str& lhs, const Str& rhs)
{
	if (strcmp(lhs.c_str(), rhs.c_str()) <= 0)
		return 1;
	return 0;
}
bool operator>  (const Str& lhs, const Str& rhs)
{
	if (strcmp(lhs.c_str(), rhs.c_str()) > 0)
		return 1;
	return 0;
}
bool operator>= (const Str& lhs, const Str& rhs)
{
	if (strcmp(lhs.c_str(), rhs.c_str()) >= 0)
		return 1;
	return 0;
}
//test example
int main()
{
	Str ex("Hello, world!");
	ex = ex + "ni hao";
		
	return 0;
}
