#include "pch.h"
#include <iostream>

using namespace std;



class Student
{
private:
	char * name;
	char grade;
public:
	
	Student()
	{
		cout << "Student 持失切" << endl;
	}

	void setName(char *n)
	{
		name = n;
	}

	char * getName()
	{
		return name;
	}
	
	void setGrade(char g)
	{
		grade = g;
	}

	char getGrade()
	{
		return grade;
	}

	~Student()
	{
		cout << "Student 社瑚切" << endl;
	}
};



class LA : public Student
{
private:
	char * cource;
public:

	LA() : cource(nullptr)
	{
		cout << "LA持失切" << endl;
	}

	void setCource(char * c)
	{
		cource = c;
	}

	char * getCource()
	{
		return cource;
	}

	~LA()
	{
		cout << "LA社瑚切" << endl;
	}
};


int main()
{

	cout << "create Student obj using default Constructor . . " << endl;
	Student student;

	cout << "create LA obj using  default Constructor . ." << endl;
	LA la;



	return 0;
}