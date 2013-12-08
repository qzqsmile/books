#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

#define N 200

using std::vector;
using std::to_string;
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::max;

void setw(const vector<int>& num,const vector<int>& result_num);

int main(void)
{
	vector<int> result_num;
	vector<int> num;

	for(int i = 1; i <= N; i++){
		num.push_back(i);
		result_num.push_back(i*i);
	}


	setw(num,result_num);

	return 0;
}

void setw(const vector<int>& num, const vector<int>& result_num)
{
	vector<string> str_num;
	string::size_type maxlen = 0;

	for (int i = 0; i < N; i++){
		str_num.push_back(to_string(num[i]));
	}

	for (int i = 0; i < N; i++){
		maxlen = max(maxlen, str_num[i].size());
	}
	for(int i = 0; i < N; i++){
		cout << num[i] <<string(maxlen + 1 - str_num[i].size(),' ') <<result_num[i] << endl;
	}
}
