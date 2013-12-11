#include<iostream>
#include<vector>
#include<string>
#include<vector>

#define N 10

using std::cout;		using std::cin;
using std::endl;        using std::string;
using std::vector;

int main(void)
{
	cout << "Please input your article:"<<endl;
    string word;
    vector<string> sentence;
    int count_sentence[N] = {0};

    while (cin >> word){
       sentence.push_back(word);
       for (int i = 0; i < sentence.size(); i++){
             if (word == sentence[i]){
                count_sentence[i]++;
                break;
             }
       }
    }

    cout << "The count of the number is" << endl;
    for (int i = 0; count_sentence[i] != 0; i++){
        cout << sentence[i] << " " << count_sentence[i] << endl; 
    }

	return 0;
}
