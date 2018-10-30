// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일입니다. 성공하려면 컴파일이 필요합니다.

#include "pch.h"

// 일반적으로 이 파일을 무시하지만 미리 컴파일된 헤더를 사용하는 경우 유지합니다.

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
		cout << this->name << "의 소멸자 호출" << endl;
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

	cout << sn->getName() << "의 멘토 : " << sn->getMentor()->getGrade() << "학년 " << sn->getMentor()->getName() << endl;

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