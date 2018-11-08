#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;



class Triangle
{
	
public:

	Triangle() {};
	
	void setW(double w)
	{
		weight = w;
	}

	double getW()
	{
		return weight;
	}

	void setH(double h)
	{
		height = h;
	}

	double getH()
	{
		return height;
	}

	double area()
	{
		return (height * weight) / 2;
	}

private:
	double weight;
	double height;


};


int main()
{

	ofstream ofile;
	ofile.open("data.dat", ios::out);

	if (!ofile)
	{
		cout << "ofile open error!" << endl;
		return 0;
	}

	ofile << "1,2,100,200,50,60,700,800,90,10,90,80,70,60,50,40,30,2,1,4";

	ofile.close();

	Triangle * arr = new Triangle[10];

	ifstream ifile;
	ifile.open("data.dat", ios::in);


	if (!ifile)
	{
		cout << "ifile open error" << endl;
		return 0;
	}

	int idx = 0;

	char s[20];

	while (ifile.getline(s, 20, ','))
	{
		string temp = s;
		
		arr[idx].setW(atof(temp.c_str()));
	
		
		ifile.getline(s, 20, ',');
		arr[idx].setH(atof(temp.c_str()));
		idx++;

	}


	for (int i = 0; i < 10; i++)
	{
		cout << "(" << arr[i].getW() << ", " << arr[i].getW() << ") : " << arr[i].area() << endl;
	}
	

	delete[]arr;
	ifile.close();






	return 0;

}