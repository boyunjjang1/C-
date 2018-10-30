#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class PhoneList
{
	
public:

	PhoneList() {};
	PhoneList(string _name, string _number)
	{
		name = _name;
		number = _number;
	}

	void setName(string _name)
	{
		name = _name;
	}

	void setNumber(string _number)
	{
		number = _number;
	}
	

	string getNumber()
	{
		return number;
	}

	string getName()
	{
		return name;
	}

private:
	
	string name;
	string number;
	
};


int main()
{

	ifstream ifile;
	ifile.open("phone_info.txt", ios::in);

	int choice;
	cout << "몇개의 전화번호부? ";
	cin >> choice;

	PhoneList * arr = new PhoneList[choice];
	string _name;
	string _number;

	for (int i = 0; i < choice; i++)
	{
		ifile >> _name >> _number;
		arr[i].setName(_name);
		arr[i].setNumber(_number);
	}

	ifile.close();

	int th;

	cout << "Please input the n for modification: ";
	cin >> th;
	cout << "NAME: " << arr[th - 1].getName() << " please input a new name(if not, type '/'): ";
	cin >> _name;
	arr[th - 1].setName(_name);
	
	cout << "PhoneNumber: " << arr[th - 1].getNumber() << " please input a new phone number(if not, type '/):";
	cin >> _number;
	arr[th - 1].setNumber(_number);

	ofstream ofile;
	ofile.open("phone_info.txt", ios::out);
	

	for (int i = 0; i < choice; i++)
	{
		ofile << arr[i].getName() << " " << arr[i].getNumber();
	}

	return 0;

}