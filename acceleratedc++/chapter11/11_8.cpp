#include<memory>
#include<algorithm>

template<class T>class list{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef size_t size_type;
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;

	private:
		iterator data;
		iterator avail;
}
