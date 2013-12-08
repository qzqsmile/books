#include<vector>
#include<iostream>
#include<algorithm>
#include<string>

using std::string;
using std::max;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

bool is_palindrome(const string & s);
string find_max(const vector < string > &result_string);
void print_palinrome(const vector<string>& result_string);

int main(void)
{
	string x, maxlen_string;
	vector < string > result_string;

	while (cin >> x) {
		if (is_palindrome(x)) {
			result_string.push_back(x);
		}
	}
	print_palinrome(result_string);
	maxlen_string = find_max(result_string);
	cout << "The longest string is " << maxlen_string << endl;

	return 0;
}


bool is_palindrome(const string & s)
{
	string temp = s;
	string::size_type n = s.size();

	for (string::size_type i = 0; i < (n / 2); i++) {
		if (s[i] != temp[n - i - 1]) {
			return false;
		}
	}
	return true;
}

string find_max(const vector < string > &result_string)
{
	string::size_type maxlen = 0;
	string maxlen_string;

	for (vector < string >::size_type i = 0; i < result_string.size();
	     i++) {
		if (maxlen < result_string[i].size()) {
			maxlen = result_string[i].size();
			maxlen_string = result_string[i];
		}
	}

	return maxlen_string;
}

void print_palinrome(const vector<string>& result_string)
{
	cout << "The palinrome words are" << endl;

	for(vector<string> :: size_type i = 0; i < result_string.size(); i++){
		cout << result_string[i] << ' ';
	}
	cout << endl;
}
