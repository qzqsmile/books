#include<iostream>
#include<algorithm>
#include<string>
#include<memory>

using std::string;
using std::max;
using std::allocator;
using std::uninitialized_fill;
using std::uninitialized_copy;

template<class T> class Vec{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef size_t size_type;
		typedef T value_type;
        typedef std::ptrdiff_t difference_type;
		typedef T& reference;
		typedef const T& const_reference;

		Vec() {create();}
		explicit Vec(size_type n, const T& t = T()) {create(n, t);}
		Vec(const Vec& v) {create(v.begin(), v.end());}
		Vec& operator= (const Vec&);
		~Vec(){uncreate();}
		
		T& operator[](size_type i) {return data[i]; }
		const T& operator[](size_type i) const {return data[i];}

		void push_back(const T& t){
			if (avail == limit)
				grow();
			unchecked_append(t);
		}

		size_type size() const {return avail - data;}

		iterator begin() {return data;}
		const_iterator begin() const{return data;}

		iterator end() {return avail;}
		const_iterator end() const {return avail;}

        iterator erase (iterator position);
        iterator erase (iterator first, iterator last);
        void clear() {uncreate();};

	private:
		iterator data;
		iterator avail;
		iterator limit;

		allocator<T> alloc;

		void create();
		void create(size_type, const T&);
		void create(const_iterator, const_iterator);

		void uncreate();

		void grow();
		void unchecked_append(const T&);
};

template<class T> void Vec<T>::create() 
{
	data = avail = limit = 0;
}
