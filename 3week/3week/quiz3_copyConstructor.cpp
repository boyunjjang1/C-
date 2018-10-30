// pch.cpp: �̸� �����ϵ� ����� �ش��ϴ� �ҽ� �����Դϴ�. �����Ϸ��� �������� �ʿ��մϴ�.

#include "pch.h"

// �Ϲ������� �� ������ ���������� �̸� �����ϵ� ����� ����ϴ� ��� �����մϴ�.

#include <iostream>

using namespace std;

class StudentNode {

	
public:
	
	StudentNode() : gradeList(nullptr), mentor(nullptr) {};
	StudentNode(const char * name1, char grade1, StudentNode * mentor1, int size1) 
	{
		name = name1;
		grade = grade1;
		mentor = mentor1;
		size = size1;
		gradeList = new int[size1];

	};
	
	StudentNode(const StudentNode & a)
	{

		name = a.name;
		grade = a.grade;
		mentor = a.mentor;

		int tempSize = a.getSize();
		gradeList = new int[tempSize];

		for (int i = 0; i < tempSize; i++)
		{
			gradeList[i] = a.gradeList[i];
		}

	}


	~StudentNode()
	{
		
		delete[] gradeList;
		cout << this->name << "�� �Ҹ��� ȣ��" << endl;
	}
	void setName(const char * name1)
	{
		name = name1;
	}

	const char * getName()
	{
		return name;
	}

	void setMentor(StudentNode * mentor1)
	{
		mentor = mentor1;
	}

	StudentNode * getMentor()
	{
		return mentor;
	}

	void setGrade(char grade1)
	{
		grade = grade1;
	}

	char getGrade()
	{
		return grade;
	}

	int getSize() const
	{
		return size;
	}

private:
	const char * name;
	StudentNode * mentor;
	char grade;
	int * gradeList;
	int size;

};

void printMentor(StudentNode * sn)
{
	if (sn->getMentor() == nullptr)
	{
		cout << "Terminate printMenotr()" << endl;
		return;
	}

	cout << sn->getName() << "�� ���� : " << sn->getMentor()->getGrade() << "�г� " << sn->getMentor()->getName() << endl;

	printMentor(sn->getMentor());

}

int main()
{

	StudentNode c("Park", '3', nullptr, 3);
	StudentNode b("Lee", '2', &c,3);
	StudentNode a("Kim", '1', &b,3);

	printMentor(&a);

	StudentNode *s1 = new StudentNode(a); 
	cout << s1->getName() << endl;

	delete s1;
	


	return 0;

}