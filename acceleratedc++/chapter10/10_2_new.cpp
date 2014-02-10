#include <algorithm>  
#include <stdexcept>  
#include <vector>  
#include <iostream>  

using std::domain_error;  
using std::sort;  
using std::cout;  
using std::endl;  
using std::vector;  

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

int main() {  
    int test_arr[] = {1, 2, 8, 4, 5, 6, 7, 3, 9, 10};  
    vector<int> test_vec(test_arr, test_arr + 10);  

    cout << "Median: " << median<int>(test_arr, test_arr + 10) << endl;  

    for (int i = 0; i < 10; ++i)  
        cout << test_arr[i] << endl;;  

    cout << "Median: " << median<int>(test_vec.begin(), test_vec.end()) << endl;  

    for (int i = 1; i < 10; ++i)  
        cout << test_vec[i] << endl;  
    system("pause");  
    return 0;  
}  
