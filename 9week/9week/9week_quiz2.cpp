#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

class PhoneBook
{

public:
	
	PhoneBook() {};
	PhoneBook(string nm, string nb)
	{
		name = nm;
		number = nb;
	}

	void setName(string nm) { name = nm; }
	string getName() { return name; }

	void setNumber(string nb) { number = nb; }
	string getNumber() { return number; }

	


private:

	string name;
	string number;



};

int main()
{

	PhoneBook phoneBook[5];
	phoneBook[0].setName("tom"); phoneBook[0].setNumber("123456789");
	phoneBook[1].setName("sam"); phoneBook[1].setNumber("1234");
	phoneBook[2].setName("jerry"); phoneBook[2].setNumber("065421897");
	phoneBook[3].setName("may"); phoneBook[3].setNumber("2494717");
	phoneBook[4].setName("park"); phoneBook[4].setNumber("015896");

	fstream ofile;
	ofile.open("phonenumber.dat", ios::out | ios::binary);

	if (!ofile)
	{
		cout << "open Error!" << endl;
		return 0;
	}

	for (int i = 0; i < 5; i++)
	{
		ofile.write((char*)&phoneBook[i], sizeof(phoneBook[i]));
	}

	ofile.close();

	
	cout << " Please input the n for modification : ";
	int choice;
	cin >> choice;


	string newName;
	string newNumber;

	PhoneBook entryTemp;


	if (choice > 5)
		cout << "the number is out of the telephonebook! " << endl;

	else
	{

		cout << "NAME:  " << phoneBook[choice-1].getName() << " please input a new name(if not, type '/'): ";
		cin.clear();
		cin >> newName;
		cout << "phoneNumber:  " << phoneBook[choice-1].getNumber() << " please input a new phone number(if not, type '/'):";
		cin >> newNumber;

		phoneBook[choice-1].setName(newName);
		phoneBook[choice-1].setNumber(newNumber);

		ofile.open("phonenumber.dat", ios::in | ios::out | ios::binary);

		ofile.seekp((choice - 1) * sizeof(PhoneBook), ios::beg);
		ofile.write(reinterpret_cast<char *>(&phoneBook[choice-1]), sizeof(phoneBook[choice-1]));

		ofile.close();
		

		ofile.open("phonenumber.dat", ios::in | ios::binary);
		if (!ofile)
			cout << "ofile open error!" << endl;

		ofile.seekg(0, ios::beg);

		for (int i = 0; i < 5; i++)
		{
			ofile.read(reinterpret_cast<char *>(&phoneBook[i]), sizeof(phoneBook[i]));
		}

		for (int i = 0; i < 5; i++)
		{
			cout << phoneBook[i].getName() << " " << phoneBook[i].getNumber() << endl;
		}
	}

	ofile.close();

	return 0;


}