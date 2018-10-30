#include "pch.h"
#include <iostream>
#include <string>


using namespace std;

void typing(string origin, string input)
{
	if (origin == input)
		cout << "Correct Answer !" << endl;
	else
		cout << "Wrong Answer !" << endl;
}

int main()
{

	string root = "Hello World!";
	
	char input[20];
	cin.getline(input, 20);
	typing(root, input);

	

	return 0;


}
