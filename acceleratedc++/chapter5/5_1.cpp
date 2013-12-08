#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

void sort(vector<string>& sort_string);
void print_string(const vector<string>& sort_string);

int main(void)
{
	cout << "Please input the words" << endl;	
	string x;
	vector<string> sort_string;
	while(cin >> x){
		sort_string.push_back(x);
	}

	for (int i = 0; i < sort_string.size(); i++){
		sort(sort_string);
		print_string(sort_string);
	}
	return 0;
}

void sort(vector<string>& sort_string)
{
	vector<string> temp_string;

	for (int i = 1; i < sort_string.size(); i++){
		temp_string.push_back(sort_string[i]);
	}
	temp_string.push_back(sort_string[0]);

	sort_string = temp_string;
}

void print_string(const vector<string>& sort_string)
{
	for (int i = 0; i < sort_string.size(); i++){
		cout << sort_string[i] << ' ';
	}
	cout << endl;
}
