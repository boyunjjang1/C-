// 3week.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Complex
{

	friend Complex addComplex(Complex a, Complex b);

public:

	Complex() :real(0), imagine(0) {};


	void setReal(int r)
	{
		real = r;
	}


	void setImg(int img)
	{
		imagine = img;
	}

	void print()
	{
		cout << real << " + " << imagine << "i" << endl;
	}
	
	
private:
	int real;
	int imagine;

};

Complex addComplex(Complex a, Complex b)
{
	a.real += b.real;
	a.imagine += b.imagine;

	return a;
}

int main()
{

	cout << "�� �� ?";
	
	int choice;
	cin >> choice;
	
	unique_ptr<Complex[]> arr(new Complex[choice]);

	int realNum;
	int imgNum;
	char temp;

	for (int i = 0; i < choice; i++)
	{
		cout << "�Է��ϼ��� : ";
		cin >> realNum >> temp >> imgNum >> temp;
		Complex a;
		a.setReal(realNum);
		a.setImg(imgNum);

		Complex b;
		cin >> realNum >> temp >> imgNum >> temp;
		b.setReal(realNum);
		b.setImg(imgNum);
		
		
		Complex temp = addComplex(a, b);

		arr[i] = temp;
		
	}

	for (int i = 0; i < choice; i++)
	{
		arr[i].print();
	}

}

