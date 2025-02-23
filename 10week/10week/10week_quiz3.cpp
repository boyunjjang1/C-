#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class StudentNode {

	friend class LinkedList;

private:
	string name;
	string studentNumber;
	
	StudentNode * next;

public:
	StudentNode() {};

	void setName(string _name)
	{
		name = _name;
	}

	string getName()
	{
		return name;
	}

	void setStudentNumber(string _studentNumber)
	{
		studentNumber = _studentNumber;
	}

	void setNext(StudentNode * _next)
	{
		next = _next;
	}


	
};



class LinkedList {

public:
	LinkedList() {};
	
	void setHead(StudentNode * _head)
	{
		head = _head;
	}

	void insert(string _name, string _studentNumber)
	{

		StudentNode * newNode = new StudentNode;
		newNode->setName(_name);
		newNode->setStudentNumber(_studentNumber);

		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			StudentNode * temp = head;

			while (true)
			{
				if (temp->studentNumber > _studentNumber)
				{
					head = newNode;
					head->next = temp;
					
					break;

				}

				if (temp->studentNumber < _studentNumber && temp->next == nullptr)
				{
					temp->next = newNode;
					break;	
				}
				temp = temp->next;
			}
		}

	}

	void print()
	{

		StudentNode * temp = head;

		while (temp != nullptr)
		{
			cout << "이름 : " << temp->name << " 학번 : " << temp->studentNumber << endl;
			temp = temp->next;
		}

	}


private:
	
	StudentNode * head = nullptr;
	
	
};


int main()
{



	LinkedList list;

	ifstream ifile;
	ifile.open("student.txt", ios::in);

	if (!ifile)
	{
		cout << "ifile open error" << endl;
		return 0;
	}

	string tempName;
	string tempNumber;

	char c;

	while (ifile >> tempName)
	{
		ifile >> tempNumber;
		list.insert(tempName, tempNumber);
	}

	ifile.close();
	
	list.print();



	return 0;


}