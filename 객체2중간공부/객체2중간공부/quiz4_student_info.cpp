#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student
{

public:
	Student(){};
	
	Student(string n, string g)
	{
		name = n;
		grade = g;
	}
	
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
	const int INDEX = 4;
	
	Student arr[INDEX];
	
	ifstream ifile;
	ifile.open("student_info.txt", ios::in);
	
	for (int i = 0; i < INDEX;i++)
	{
		string n;
		string g;
		ifile >> n >> g;
		arr[i].setName(n);
		arr[i].setGrade(g);
	}
	
	
	for (int i = 0; i < INDEX; i++)
	{
		cout << arr[i].getName() << " " << arr[i].getGrade() << endl;
	}




	return 0;

}
