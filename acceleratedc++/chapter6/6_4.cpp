#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using std::string;
using std::copy;
using std::vector;
using std::cout;
using std::endl;

int main(void)
{
	vector<int> u{10, 100};
	vector<int> v;

    // solution 1
	//copy(u.begin(),u.end(),back_inserter(v));
    // solutin 2
    v.insert(v.end(), u.begin(), u.end());
    
	cout << v[0] << ' ' << v[1] << endl;
//	cout << u[0] << ' ' << u[1] <<endl;	cout << v[0] << ' ' << v[1] << endl; 
	return 0;
}
