#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	
	int x = 10000;

	cout << x << "printed as int right and left justified\n"
		<< "and as hex with internal justification.\n"
		<< "Using the default pad character (space): " << endl;

	cout << showbase << setw(10) << x << endl;
	cout << left << setw(10) << x << endl;

	cout << internal << setw(10) << hex << x << endl << endl;
	cout << right;
	cout.fill('*');
	cout << setw(10) << dec << x << endl;

	cout << endl << endl;
	
	cout << left << setw(10) << setfill('%') << x << endl;

	cout << internal << setw(10) << setfill('^') << hex << x << endl;

	

	return 0;


}
