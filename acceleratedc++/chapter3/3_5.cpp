#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::streamsize;
using std::setprecision;
using std::sort;

void sort_grade(vector < double >& homework, char n);
int main(void)
{
	cout << "Please input names" << endl;
	string temp_name;
	char count = 0;
	char grade_count = 0;
	vector < string > student_name;

	while (cin >> temp_name) {	//Ture when meet space,false when meet eof
		student_name.push_back(temp_name);
		count++;
	}

	cin.clear();
	cout << "Please input your midterm and final exam grades" << endl;

	double temp_midterm, temp_final;
	vector < double >midterm, final;
	while (cin >> temp_midterm >> temp_final) {	//
		midterm.push_back(temp_midterm);
		final.push_back(temp_final);
	}
	cin.clear();

	cout << "Enter all your homework grade,followed by end-of-file" <<
	    endl;
	vector < double >homework;
	double temp_homework;

	while (cin >> temp_homework) {
		homework.push_back(temp_homework);
	}
	cin.clear();

	typedef vector < double >::size_type vec_sz;
	vec_sz size = homework.size();
	if (0 == size) {
		cout << endl << "You must enter your grades, " << endl;
		return 1;
	}

	grade_count = homework.size() / count;

	sort_grade(homework, grade_count);

	vec_sz mid = grade_count / 2;
	vector < double >median;
	if (grade_count % 2) {
		for (int i = 0; i < count; i++) {
			median.push_back(homework[mid + i * grade_count]);
		}
	} else {
		for (int i = 0; i < count; i++) {
			median.push_back(
			   (homework[mid + i * grade_count] +
			    homework[mid - 1 + i * grade_count]) / 2);
		}
	}

	streamsize prec = cout.precision();
	for (int i = 0; i < count; i++) {
		cout << student_name[i] << " final grade is " <<
		    setprecision(3) << 0.2 * midterm[i] + 0.4 * final[i] +
		    0.4 * median[i] << setprecision(prec) << endl;
	}
	return 0;
}

void sort_grade(vector < double >& homework, char n)
{
	vector < double >sperate_homework;

	for (int i = 0; i < homework.size(); i = i + n) {
		for (int j = 0; j < n; j++) {
			sperate_homework.push_back(homework[i + j]);
		}
		sort(sperate_homework.begin(), sperate_homework.end());
		for (int j = 0; j < n; j++) {
			homework[i + j] = sperate_homework[j];
		}
		sperate_homework.clear();
	}
}
