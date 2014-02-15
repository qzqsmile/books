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
			alloc.destroy(--it);
		
		alloc.deallocate(data, limit - data);
	}

	data = limit = avail = 0;
}

template<class T> void Vec<T> :: grow()
{
	//version1
//    size_type new_size = max(2 * (limit - data), std::ptrdiff_t(1));
	//version2
	size_type new_size = max(1 * (limit - data), std::ptrdiff_t(1)) + 1;

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template <class T> void Vec<T> :: unchecked_append(const T& val)
{
    alloc.construct(avail++, val);
}

template<class T> T* Vec<T> :: erase(T* position)
{
	iterator new_data = alloc.allocate((limit - data - 1));	
	iterator new_avail = new_data + (avail - data - 1);
	iterator new_limit = new_data + (limit - data - 1);
	iterator i = data, j = new_data;
	iterator locate_iterator;

	while (i != position)
		*j++ = *i++;

	locate_iterator = j;
	i++;

	while(i != avail)
		*j++ = *i++;

	uncreate();

    data = new_data;
    avail = new_avail;
    limit = new_limit;
	
	return locate_iterator;

}
template<class T> T* Vec<T> :: erase(T* first, T* last)
{
	size_type new_size = (limit - data) - (last - first);
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = new_data + (avail - data) - (last - first); 
	iterator new_limit = new_data + new_size;
	iterator i = data, j = new_data;
	iterator locate_iterator;

	while (i != first)
		*j++ = *i++;
	i = last + 1;
	locate_iterator = i;
	while (i != avail)
		*j++ = *i++;
	
	uncreate();

    data = new_data;
 ///   avail = new_avail;
    limit = new_limit;

	return locate_iterator;
}

int main()
{
	//test example
	Vec<int> data;
	for (int i = 0; i < 30000; i++)
		data.push_back(i);
	
	std::cout << data[29999] << std::endl;

//	for (int i = 0; i < 10; i++)
//		std::cout << data[i] << std::endl;
//
//	data.erase(data.begin(), data.begin() + 1);
//	for (int i = 0; i < 9; i++)
//		std::cout << data[i] << std::endl;
//	data.clear();

	return 0;
}
