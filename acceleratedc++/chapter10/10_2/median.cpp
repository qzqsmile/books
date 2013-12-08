#include<algorithm>
#include<stdexcept>
#include<vector>

using std::domain_error;
using std::sort;
using std::vector;

//double median(vector<double> vec)
//{
//	typedef vector<double>::size_type vec_sz;
//
//	vec_sz size = vec.size();
//	if (0 == size)
//		throw domain_error("median of an empty vector");
//
//	sort(vec.begin(), vec.end());
//
//	vec_sz mid = size / 2;
//
//	return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
//}

template <class T, class Iterator>
T median(Iterator begin, Iterator end) {
	if (begin == end)
		throw domain_error("median of an empty container");

	vector<T> temp;

	for ( ; begin != end; ++begin)
		temp.push_back(*begin);

	sort(temp.begin(), temp.end());

	size_t mid = temp.size() / 2;

	T ret = (temp.size() % 2 == 0)
		? (temp[mid] + temp[mid - 1]) / 2
		: temp[mid];

	return ret;
}
