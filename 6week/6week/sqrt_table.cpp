#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{

	
	fstream Sqrt;
	Sqrt.open("sqrt.txt", ios::out);


	cout << setw(4) << "|";
	Sqrt << setw(4) << "|";
	cout << setw(2) << " ";
	Sqrt << setw(2) << " ";

	for (int i = 0; i < 10; i++)
	{
		cout << left;
		Sqrt << left;
		cout << setw(6) << i;
		Sqrt << setw(6) << i;
 }
	cout << endl;
	Sqrt << endl;
	
	for (int i = 0; i < 65; i++)
	{
		cout << "-";
		Sqrt << "-";
	}

	cout << endl;
	Sqrt << endl;


	int st;
	int temp;



	for (int i = 0; i < 10; i++)
	{
		cout << i << "    |";
		Sqrt << i << "    |";

		for (int j = 0; j < 10; j++)
		{
			st = (i * 10) + j;


			


			cout << setprecision(4) << fixed;
			Sqrt << setprecision(4) << fixed;
			cout << setw(5) << sqrt(st) << "  ";
			Sqrt << setw(5) << sqrt(st) << " ";

		}
		cout << endl;
		Sqrt << endl;
	}

	
	/*
	ofstream table;
	table.open("squrtale.txt");
	int i, j;
	if (!table)
	{
		cout << "cannot open output file! \n";
		return 1;
	}
	table << "   |";
	for (i = 0; i < 10; i++)
		table << setw(5) << i << "   ";
	table << endl;
	table << "---+";
	for (i = 0; i < 10; i++)
		table << "--------";
	table << fixed << setprecision(4);
	for (i = 0; i < 10; i++)
	{
		table << endl;
		table << setw(2) << i << "   |";
		for (j = 0; j < 10; j++)
			table << setw(8) << sqrt(10 * i + j);
	}
	table.close();

	
	*/

	return 0;


}
