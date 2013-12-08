#include<iostream>
#include<string>
#include<fstream>
#include<stdexcept>

using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::cerr;

int main(int argc, char** argv)
	using std::cerr;
{
//	if(argc > 1){
//		cout << argv[1];
//
//		for (int i = 2; i != argc; ++i)
//			cout << " " << argv[i];
//	}
//	cout << endl;
//
//	ifstream infile("in");
//	ofstream outfile("out");
//	
//	string s;
//
//	while (getline(infile, s))
//		outfile << s << endl;
	
	int fail_count = 0;

	for (int i = 1; i < argc; ++i){
		ifstream in(argv[i]);

		if (in){
			string s;
			while (getline(in, s))
				cout << s << endl;
		}else{
			cerr << "cannot open file " << argv[i] << endl;
			++fail_count;
		}
	}

	return 0;
}

//string letter_grade(double grade)
//{
//	static const double numbers[] = {
//		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
//	};
//	static const char* const letters[] = {
//		"A+","A","A-","B+","B","B-","C+","C","C-","D","F"
//	};
//	static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);
//
//	for (size_t i = 0; i < ngrades; ++i){
//		if(grade >= numbers[i])
//			return letters[i];
//	}
//
//	return "?\?\?";
//}
