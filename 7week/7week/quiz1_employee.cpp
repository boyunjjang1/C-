// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일입니다. 성공하려면 컴파일이 필요합니다.

#include "pch.h"

// 일반적으로 이 파일을 무시하지만 미리 컴파일된 헤더를 사용하는 경우 유지합니다.


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

	cout << "현재 레코드의 총 개수: ";
	
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
	cout << "현재 레코드의 총 개수 : " << total << endl;

	cout << "# 파일에서 읽고자 하는 위치: ";
	int choice;
	cin >> choice;

	if (choice > total)
	{
		cout << "레코드 수 초과" << endl;
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