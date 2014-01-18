#include<iostream>
#include<iterator>
#include<stdexcept>
#include<algorithm>
#include<vector>
#include<string>

using std::vector;
using std::cin;
using std::cout;
using std::string;
//using std::copy;
using std::istream_iterator;
using std::ostream_iterator;
using std::domain_error;

template <class T>
T median(vector<T> v)
{
	typedef typename vector<T>::size_type vec_sz;

	vec_sz size = v.size();
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(v.begin(), v.end());
	
	vec_sz mid = size / 2;

	return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

template <class In, class X> In find(In begin, In end, const X& x)
{
	while (begin != end && *begin != x)
		++begin;

	return begin;
}

//template <class In , class X>In find(In begin, In end, const X& x)
//{
//	if (begin == end || *begin == x)
//		return begin;
//	begin++;
//	
//	return find(begin, end, x);
//}

template <class In, class Out>
Out copy(In begin, In end, Out dest)
{
	while (begin != end)
		*dest++ = *begin++;
	return dest;
}

template <class For, class X>
void replace(For beg, For end, const X& x, const X& y)
{
	while (beg != end){
		if(*beg == x)
			*beg = y;
		++beg;
	}
}

template <class Bi> void reverse(Bi begin, Bi end)
{
	while (begin != end){
		--end;
		if (begin != end)
			swap(*begin++, *end);
	}
}

template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
    while (begin < end){
        Ran mid = begin + (end - begin) / 2;
        if (x < *mid)
            end = mid;
        else if (*mid < x)
            begin = mid + 1;
        else return true;
    }
    return false;

}

struct Student{
    int name;
    int midterm;
    int final;
};

//template <class Out>
//void split (const string& str, Out os){
//    typedef string:: const_iterator iter;
//
//    iter i = str.begin();
//    while (i != str.end()){
//        i = find_if(i, str.end(), not_space);
//        iter j = find_if(i, str.end(), space);
//
//        if (i != str.end())
//            *os++ = string(i, j);
//        i = j;
//    }
//}

int main(void)
{
	return 0;
}
