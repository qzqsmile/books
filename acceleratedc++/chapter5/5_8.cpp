#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using std::vector;
using std::getline;
using std::endl;
using std::cout;
using std::string;
using std::max;
using std::cin;

vector<string> hcat(const vector<string>& left, const vector<string>& right);
string::size_type width(const vector<string>& v);
vector<string> frame(const vector<string>& v);
void print_string(const vector<string>& s);

int main(void)
{
	string x;
	vector<string> left, right, ret;
	
//	while (getline(cin,x)){
//		left.push_back(x);
//	}
    left.push_back("this is an");
    left.push_back("example");
    left.push_back("to");
    left.push_back("illustrate");
    left.push_back("framing");

	right = frame(left);
	//print_string(left);
	//print_string(right);
	ret = hcat(left,right);
	print_string(ret);
	return 0;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;

	string::size_type width1 = width(left) + 1;
	vector<string> :: size_type i = 0, j = 0;

	//string s;
    //when the left string is output it will cause error
    // because string s will intilaite the s to null string
    //when i == left.size() the s will remain the last string ,
    //which left.size() is 25, and width1-s.sizes() is negative,
    // and cause a error
	while(i != left.size() || j != right.size()){
        string s;

		if (i != left.size())
			s = left[i++];

		s += string(width1 - s.size(), ' ');

		if (j != right.size())
			s += right[j++];

		ret.push_back(s);
	}

	return ret;
}


string::size_type width(const vector<string>& v)
{
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); ++i)
		maxlen = max(maxlen,v[i].size());
	return maxlen;
}

vector<string> frame(const vector<string>& v)
{
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');

	ret.push_back(border);
	
	for(vector<string> :: size_type i = 0; i != v.size(); ++i){
		ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
	}
		ret.push_back(border);
		return ret;
}

void print_string(const vector<string>& s)
{
	for (vector<string> :: size_type i = 0; i < s.size(); i++){
		cout << s[i] << endl;
	}
}
