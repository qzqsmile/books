#include<iostream>
#include<cstring>
#include<memory>
#include<algorithm>
#include"Vec"

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
		iterator last;
		size_type length;

		allocator<char> alloc;
		void create(size_type, char);
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

void Str :: create(size_type n, char val)
{
	length = n + 1;
	last = alloc.allocate(length);
	uninitialized_fill(last, last + length - 1, val);
	alloc.construct(last + length - 1, '\0');
}

template<class In> void  Str :: create (In i, In j)
{
	length = j - i + 1;
	last = alloc.allocate(length);
	uninitialized_copy(i, j, last);
	alloc.construct(last + length - 1, '\0');
}

void Str :: uncreate()
{
	if (last) {
		iterator it = last + length;
		while (it != last) alloc.destroy(--it);
		alloc.deallocate(last, length);
	}

	last = 0;
	length = 0;
}

void Str :: grow(size_type )
{

}

int main()
{
	return 0;
}
