#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<vector>

using std::vector;
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

//template <class In, class X> In find(In begin, In end, const X& x)
//{
//	while (begin != end && *begin != x)
//		++begin;
//
//	return begin;
//}

template <class In , class X>In find(In begin, In end, const X& x)
{
	if (begin == end || *begin == x)
		return begin;
	begin++;
	
	return find(begin, end, x);
}

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

int main(void)
{
	return 0;
}
