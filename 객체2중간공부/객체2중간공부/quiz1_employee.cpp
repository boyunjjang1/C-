#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

class Employee
{
public:

	Employee() {};
	Employee(const char * _name, int _year, const char * _live)
	{
		strcpy_s(name, _name);
		year = _year;
		strcpy_s(live, _live);
	}



private:
	char name[20];
	int year;
	char live[20];
};

int main()
{

	ifstream ifile;
	ifile.open("employee.dat", ios::in);

	int total_count = 0;
	int position = 0;

	char c = 0;
	
	ofstream ofile;
	ofile.open("employee2.dat", ios::out);

	while (!ifile.eof())
	{
		ifile.get(c);
		
		if (c == '\n')
		{
			if (total_count == 0)
				position = ifile.tellg();

			total_count++;
		}

	}
	ifile.clear();
	cout << "현재 레코드의 총 개수: " << total_count << endl;

	cout << "# 파일에서 읽고자 하는 위치 : ";
	int posInput;
	cin >> posInput;

	ifile.seekg((posInput - 1) * position, ios::beg);

	while (ifile.get(c))
	{
		if (c == '\n')
			break;

		cout << c;

	}

	ifile.clear();

	ifile.seekg(0, ios::beg);

	while (ifile.get(c))
	{
		ofile.put(c);
	}

	ifile.close();
	ofile.close();

	return 0;

}