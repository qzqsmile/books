#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using std::cout;		using std::setprecision;
using std::cin;			using std::vector;		
using std::sort;		using std::streamsize;
using std::endl;

int main()
{
	cout<<"Please input integer(followed by end-of-file):"<<endl;
	
	vector<int> num;
	int x;
	while(cin >> x)
	{
		num.push_back(x);
	}

	typedef vector<int>::size_type vec_sz;

	sort(num.begin(),num.end());
	vec_sz size = num.size();
	vec_sz quar = size / 4;
	
	int quar_num = num[quar-1];
	cout << "The quartily number is " << quar_num << endl;
	
	return 0;
}
