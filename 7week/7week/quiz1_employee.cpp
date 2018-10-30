// pch.cpp: �̸� �����ϵ� ����� �ش��ϴ� �ҽ� �����Դϴ�. �����Ϸ��� �������� �ʿ��մϴ�.

#include "pch.h"

// �Ϲ������� �� ������ ���������� �̸� �����ϵ� ����� ����ϴ� ��� �����մϴ�.


#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class Employee {

public:
	
	Employee() : name(""), age(0), grade("") {};


private:
	char name[20];
	int age;
	char grade[20];

};

int main()
{

	Employee employee;

	ifstream ifile;
	ifile.open("empoyee.dat", ios::in);

	cout << "���� ���ڵ��� �� ����: ";
	
	if (ifile.fail()) {
		cout << "File Open Error" << endl;
		return 0;
	}


	char c ;

	int total = 0;
	int recordSize = 0;

	while (ifile.get(c))
	{
		cout << c;
		if (c == '\n')
		{

			if(recordSize == 0)
				recordSize = ifile.tellg();

			total++;
		}
	}

	ifile.clear();
	cout << "���� ���ڵ��� �� ���� : " << total << endl;

	cout << "# ���Ͽ��� �а��� �ϴ� ��ġ: ";
	int choice;
	cin >> choice;

	if (choice > total)
	{
		cout << "���ڵ� �� �ʰ�" << endl;
	}


	int modify = 0;

	ifile.seekg((choice - 1) *  recordSize, ios::beg);
	while (ifile.get(c))
	{
		if (c == '\n')
		{
			break;
		}

		cout << c;

	}

	ifile.clear();

	ifile.seekg(0, ios::beg);
	
	ofstream ofile;
	ofile.open("employee2.dat", ios::out);

	while (ifile.get(c))
	{
		ofile.put(c);
	}


	return 0;

}