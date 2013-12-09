#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::cin;

int main()
{
	int square_row, rectangle_long, rectangle_wide, triangle_row;

	cout << "Please input the row of square ";
	cin >> square_row;

	for (int i = 0; i < square_row; i++) {
		cout << string(square_row, '*');
        cout << endl;
	}

	cout << "Please input the long and wide of rectangle ";
	cin >> rectangle_long >> rectangle_wide;

	for (int i = 0; i < rectangle_wide; i++) {
		cout << string(rectangle_long, '*');
        cout << endl;
	}

	cout << "Please input the number of '*' in the triangle bottom (must be odd) ";
	cin >> triangle_row;

    if (0 == (triangle_row % 2))
    {
        cout << "you input is not a odd number" << endl;
        return 1;
    }
	for (int i = 0; i < (triangle_row + 1) / 2; i++) {
		cout << string(((triangle_row - 1) / 2 - i), ' ');
		cout << string((i * 2 + 1), '*');
		cout << string(((triangle_row - 1) / 2 - i), ' ');
        cout << endl;
	}

	return 0;
}
