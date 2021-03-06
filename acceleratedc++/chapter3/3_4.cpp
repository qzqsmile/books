#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{
    string max_string, temp_string, min_string;
    string::size_type max_count = 0, temp_count = 0, min_count = 0;
    cout << "Plseae input words" << endl;

    cin >> temp_string;
    max_count = temp_string.size();
    min_count = temp_string.size();
    max_string = min_string = temp_string;

    while (cin >> temp_string) {
        temp_count = temp_string.size();
        if (temp_count > max_count) {
            max_count = temp_count;
            max_string = temp_string;
        }
        if (temp_count < min_count) {
            min_count = temp_count;
            min_string = temp_string;
        }

    }

    cout << "The longest and shortest string is  " << max_string <<"        "<< min_string
        << endl;

    return 0;
}
