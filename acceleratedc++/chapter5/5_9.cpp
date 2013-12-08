#include<iostream>
#include<cctype>
#include<ios>
#include<string>
#include<vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

vector < string > erase_uppercase_letter(const vector < string >
					 &input_string);
bool is_uppercase_word(const string & x);
void print_letter(const vector < string > &x);

int main(void)
{
	string x;
	vector < string > input_string, result_letter;

	while (cin >> x) {
		input_string.push_back(x);
	}
	result_letter = erase_uppercase_letter(input_string);
	print_letter(result_letter);

	return 0;
}

vector < string > erase_uppercase_letter(const vector < string >
					 &input_string)
{
	vector < string > result_letter;
	for (vector < string >::size_type i = 0; i < input_string.size();
	     i++) {
		if (!is_uppercase_word(input_string[i])) {
			if ( (0 == i) || (is_uppercase_word(input_string[i - 1]))){
				result_letter.push_back(input_string[i]);
			}
		}
	}
	return result_letter;
}

bool is_uppercase_word(const string & x)
{
	for (string::size_type i = 0; i < x.size(); i++) {
			if (isupper(x[i])){
				return 1;
			}
	}
	return 0;
}

void print_letter(const vector < string > &x)
{
	for (vector < string >::size_type i = 0; i < x.size(); i++) {
		cout << x[i] << endl;
	}
}
