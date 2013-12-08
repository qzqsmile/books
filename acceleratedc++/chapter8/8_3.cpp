#include<iostream>
#include<stdexcept>
#include<vector>
#include<algorithm>

using std::domain_error;
using std::vector;

template <class T,class In>
T median(In begin,In end)
{
	typedef typename vector<T>::iterator vec_sz;
	char size  = end - begin;

	if(begin == end)
		throw domain_error("median of an empty vector");

	sort(begin, end);
	char mid = size / 2;;

	return size % 2 == 0 ? (*(begin + mid) + *(begin + mid - 1)) / 2 :*(begin + mid);
}

int main(void)
{
	return 0;
}
