#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{



	cout << "Before using showpoint" << endl;
	cout << "9. 9900 print as: " << 9.9900 << endl;
	cout << endl << endl;


	cout << setprecision(6) << fixed;
	cout << showpoint << "After using showpoint" << endl;
	cout << "9.9900 print as: " << 9.9900 << endl;
	cout << endl << endl;


	return 0;


}
