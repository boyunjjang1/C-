#include "pch.h"
#include <iostream>

using namespace std;

class SoSimple
{
private:
	int num;

public:
	SoSimple(int n) : num(n) {};
	
	SoSimple& AddNum(int n)
	{
		num += n;
		return *this;
	}

	void showData() const
	{
		cout << "num: " << num << endl;
	}
};


int main()
{

	const int a = 10;
	const SoSimple obj(7);
	
	obj.AddNum(20);
	obj.showData();




	return 0;

}