#include<iostream>
#include<string>
#include<vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istream;

istream & read(istream & cin, vector < string >& words);
void count_words(const vector < string > &words);

int main(void)
{
	vector < string > words;
	cout << "Please input your words" << endl;
	read(cin, words);

	count_words(words);
	cout << "You has input " << words.size() << " words" << endl;
	return 0;
}


istream & read(istream & cin, vector < string >& words)
{
	string temp_string;

	while (cin >> temp_string) {
		words.push_back(temp_string);
	}

	return cin;
}

void count_words(const vector < string > &words)
{
	vector < string > num_word;
	vector < int >count_word;
	char flag = 0;
	char num_count = 1;

	for (int i = 0; i < words.size(); i++)
	{
		count_word.push_back(0);
	}
	num_word.push_back(words[0]);
	count_word[0]++;
	for (int i = 1; i < words.size(); i++) {
		for (int j = 0; j < num_word.size(); j++) {
			if (words[i] == num_word[j]) {
				flag = 1;
				count_word[j]++;
				break;
			}
		}
		if (!flag) {
			num_word.push_back(words[i]);
			count_word[num_count]++;
			num_count++;
		}
		flag = 0;
	}

	for (int i = 0; i < num_word.size(); i++) {
		cout << num_word[i] << " has occured " << count_word[i] <<
		    " times" << endl;
	}
}
