#include<iostream>
#include<memory>

template <class T> class allocator{
public:
	T* allocate(size_t);
	void deallocate(T*, size_t);
      	void construct(T*, const T&);
	void destroy(T*);
};

template<class T> class Vec{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef size_t size_type;
		typedef T value_type;
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

template <class T> void Vec<T>::create()
{
	data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data + n;
	uninitialized_fill(data, limit, val);
}

template <class T> 
void Vec<T>::create(const_iterator i, const_iterator j)
{
	data = alloc.allocate(j - i);
	limit = avail = uninitialized_copy(i, j, data);
}

template <class T> Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	if (&rhs != this){
		uncreate();
		create(rhs.begin(), rhs.end());
	}

	return *this;
}

template <class T> void Vec<T>::uncreate()
{
	if (data){
		iterator it = avail;
		while(it != data)
			alloc.destory(--it);
		
		alloc.deallocate(data, limit - data);
	}

	data = limit = avail = 0;
}

int main()
{
	return 0;
}
