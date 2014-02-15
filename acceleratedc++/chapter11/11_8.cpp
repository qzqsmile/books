#include<memory>
#include<algorithm>

using std::allocator;

template<class T>class list{
	public:
		typedef struct point_data{
			T* pre;
			T	_data;
			T* next;
		} list_data;
		typedef list_data* iterator;
		typedef const list_data* const_iterator;
		typedef size_t size_type;
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;

		list() {create();}
		explicit list(size_type n, const T& t = T()) {create(n, t);}
		list(const list& v) {create(v.begin(), v.end());}
		list& operator= (const list&);
		~list(){uncreate();}

		iterator begin() {return data;}
		const_iterator begin() const{return data;}

		iterator end() {return avail;}
		const_iterator end() const {return avail;}

		void push_back(const list_data& t){
			unchecked_append(t);
		}

	private:
		iterator data;
		iterator avail;

		allocator<list_data> alloc;

		void create();
		void create(size_type, const T&);
		void create(const_iterator, const_iterator);
		
		void uncreate();

		void unchecked_append(const list_data&);
};

template<class T> void list<T> :: create()
{	
	data = avail = alloc.allocate(1);
	avail->next = 0;
}

template <class T> void list<T>::create(size_type n, const T& val)
{	
	list_data temp, current_data;
	create();
	data._data = val;

	current_data = data;
	for (int i = 0; i != n; i++){
		temp = alloc.allocate(1);	
		temp._data = val;
		current_data.next = temp.pre;
		current_data = temp;
	}

	avail = alloc.allocate(1);
	avail.pre = current_data.next;
	avail.next = 0;
}

template<class T> void list<T> ::  create(const_iterator i, const_iterator j)
{
	data = alloc.allocate(j - i);
	avail = data = uninitialized_copy(i, j, data);
}

template<class T> void list<T> :: uncreate()
{
	if (data.next != 0)
	{
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);
		
		alloc.deallocate(data, avail - data);
	}
}

template<class T> void list<T> :: unchecked_append(const list_data& val)
{	
	avail.next = val.pre;
	avail = val;
	avail.next = 0;
}

template<class T> list<T>& list<T>::operator= (const list& rhs)
{
	if (&rhs != this){
		uncreate();
		create(rhs.begin(), rhs.end());
	}

	return *this;
}

int main(void)
{
	list<int> a;
	return 0;
}
