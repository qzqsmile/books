#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool is_ascender(const string& x);
bool is_descender(const string& x);
void print_string(const vector<string>& x);
string find_longest_word(const vector<string>& x);

int main(void)
{
	string x, longest_word;
	vector<string> ascende, descender, none;
	
	while(cin >> x){
		if(is_ascender(x)){
			ascende.push_back(x);
		}
		if(is_descender(x)){
			descender.push_back(x);
		}
		if((!is_ascender(x)) && (!is_descender(x))){
			none.push_back(x);
		}
	}

	cout << "The ascende words are" << endl;
	print_string(ascende);
	cout << "The descende words are" << endl;
	print_string(descender);
	longest_word = find_longest_word(none);
	cout << "The longest word neither ascende nor descende is " << longest_word << endl;

	return 0;
}


bool is_ascender(const string& x)
{
	for (string::size_type i = 0; i < x.size(); i++){
		if((x[i] == 'b')||(x[i] == 'd')||(x[i] == 'f')||(x[i] == 'h')||(x[i] == 'k') ||(x[i] == 'l')){
			return true;
		}
	}

	return false;
}

bool is_descender(const string& x)
{
	for (string::size_type i = 0; i < x.size(); i++){
		if((x[i] == 'g')||(x[i] == 'j')||(x[i] == 'q')||(x[i] == 'p')||(x[i] == 'y')){
			return true;
		}
	}

	return false;
}

void print_string(const vector<string>& x)
{
	for (vector<string> :: size_type i = 0; i < x.size(); i++){
		cout << x[i] << ' ';
	}
	cout << endl;
}

string find_longest_word(const vector<string>& x)
{
	string result;
	string::size_type maxlen = 0;
	
//	cout << x[0] << x[1] << endl;
	for (vector<string> :: size_type i = 0; i < x.size(); i++){
		if (maxlen < x[i].size()){
			maxlen = x[i].size();
			result = x[i];
		}
	}

	return result;
}
