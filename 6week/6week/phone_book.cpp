
#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class PhoneBook {
public:

	PhoneBook() {};
	PhoneBook(string name1, string number1) : name(name1), number(number1) {};
	void setName(string name1)
	{
		name = name1;
	}

	void setNumber(string number1)
	{
		number = number1;


	}

	string getName()
	{
		return name;
	}

	string getNumber()
	{
		return number;
	}


	void print()
	{
		cout << name << " " << number << endl;
	}

private:
	string name;
	string number;
};


int main()
{

	PhoneBook * arr = new PhoneBook[4];

	ifstream ifile;

	ifile.open("phone_info.txt", ios::in);


	int count = 0;
	string nameInput;
	string numberInput;

	if (ifile.is_open()){

		while (!ifile.eof())
		{
			ifile >> nameInput >> numberInput;
			arr[count].setName(nameInput);
			arr[count].setNumber(numberInput);
			count++;
		}
	}

	else{
		cout << "파일경로를 확인하세요." << endl;
	}

	ifile.close();
	int n;
	string newName;
	string newPhone;


	cout << "Please input the n for modification: ";
	cin >> n;

	if (n > 4)
		cout << "The number is out of the telephonebook!" << endl;
	else {
		cout << "NAME:   " << arr[n].getName() << "  " << "please input a new name(if not, type '/'): ";
		cin >> newName;
		cout << "phoneNumber:  " << arr[n].getNumber() << "  " << "please input a new phone number(if not, type '/'):  ";
		cin >> newPhone;
		arr[n].setName(newName);
		arr[n].setNumber(newPhone);
	}
	
	ofstream ofile;
	ofile.open("phone_info.txt", ios::out);

	if (!ofile)
	{
		cout << "cannot open output file! \n";
	}

	for (int i = 0; i < 4; i++)
	{
		ofile << arr[i].getName() << " " << arr[i].getNumber() << endl;
	}

	ofile.close();

	for (int i = 0; i < 4; i++)
	{
		arr[i].print();
	}

	

	delete[]arr;

	return 0;


}
