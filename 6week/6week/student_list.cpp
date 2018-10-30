
#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Student
{

public:
	
	Student() : name(""), grade("") {};
	
	void setName(string n)
	{
		name = n;
	}

	string getName()
	{
		return name;
	}

	void setGrade(string g)
	{
		grade = g;
	}

	string getGrade()
	{
		return grade;
	}


private:
	string name;
	string grade;
};

int main()
{

	ifstream studentInfo;
	studentInfo.open("student_info.txt", ios::in);

	Student stuArray[4];

	if (studentInfo.is_open())
	{
		int count = 0;
		
		while (!studentInfo.eof())
		{
			string name, grade;
			
			studentInfo >> name >> grade;
			stuArray[count].setName(name);
			stuArray[count].setGrade(grade);
			count++;
			
		}

	}

	else
	{
		cout << "파일 경로를 확인하세요,";
	}


	for (int i = 0; i < 4; i++)
	{
		cout << stuArray[i].getName() << " " << stuArray[i].getGrade() << endl;
	}

	studentInfo.close();

	return 0;


}
