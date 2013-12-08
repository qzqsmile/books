#include<iostream>

template <class T> class Vec{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef size_t size_type;

		Vec() {create();}
		explicit Vec(size_type n, const T& val = T()) { create(n, val);};
		Vec(const Vec& v) { create(v.begin(),v.end()); }
		Vec& operator= (const Vec&);
		~Vec(){uncreate();}
	prviate:
}
