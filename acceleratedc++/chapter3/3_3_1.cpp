#include <iostream>
#include <string>
#include <vector>

int main()
{
	// Ask for 
	// and read the input words
	std::cout << "Please input your words: " << std::endl;
	std::vector <std::string> word_input;
	std::string word;
//	std::vector<int> word_count;
	int word_count[3] = {0};
	char flag = 0;
	while (std::cin >> word) {
		for (int i = 0; i < word_input.size(); i++) {
			if (word_input[i] == word) {
				word_count[i]++;
				flag = 1;
			}
		}

		if (!flag) {
			word_count[word_input.size()]++;
			word_input.push_back(word);
		}
		flag = 0;
	}

	for(int i = 0; i < word_input.size(); i++)
	{
		std::cout << "The time of  " << word_input[i] << " is " <<word_count[i] << " times" << std::endl;
	}
	
	return 0;
}
