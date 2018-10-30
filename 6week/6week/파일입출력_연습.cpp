
#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>



using namespace std;


int main()
{
	
	string input;
	
	ofstream file1("test.txt", ios_base::out);
	
	while (cin >> input)
	{
		if (input == "exit")
			break;

		file1 << input;
		
	}


	file1.close();




	return 0;

}