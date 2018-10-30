#include "pch.h"
#include <iostream>
#include <cstring>


using namespace std;

class Girl;

class Boy
{

private:
	int height;

	friend class Girl;

public:
	Boy(int len) : height(len) {};

	void showYourFriendInfo(const Girl &frn);
};

class Girl
{
private:
	char phNum[20];

public:
	Girl(const char *num)
	{
		strcpy_s(phNum, num);
	}

	void ShowYourFriendInfo(Boy &frn)
	{
		cout << "His Height: " << frn.height << endl;
	}

	friend class Boy;
};

void Boy::showYourFriendInfo(const Girl &frn)
{
	cout << "Her Phone number: " << frn.phNum << endl;
}

int main()
{

	Boy boy(170);
	Girl girl("010-9779-2514");

	boy.showYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);

	return 0;

}