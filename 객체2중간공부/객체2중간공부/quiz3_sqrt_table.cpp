#include "pch.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;


int main()
{

	ofstream ofile;
	ofile.open("sqrt.txt", ios::out);

	cout << "   |  ";
	ofile << "   |  ";

	cout << left;
	ofile << left;
	for (int i = 0; i <= 9; i++)
	{
		cout << setw(6) << i;
		ofile << setw(6) << i;
	}

	cout << endl;
	ofile << endl;
	cout << "-----------------------------------------------------------------------------------------------------";
	ofile << "-----------------------------------------------------------------------------------------------------";
	cout << endl;
	ofile << endl;
	for (int i = 0; i <= 9; i++)
	{
		cout << i << "  |  ";
		ofile << i << "  |  ";

		for (int j = 0; j <= 9; j++)
		{
			cout <<  setprecision(4) << showpoint << fixed << sqrt((i * 10) + j) << " ";
			ofile << setprecision(4) << showpoint << fixed << sqrt((i * 10) + j) << " ";
		}
		cout << endl;
		ofile << endl;
	}
	

	ofile.close();


	return 0;

}