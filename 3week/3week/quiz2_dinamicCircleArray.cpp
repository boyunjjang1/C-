
#include "pch.h"

// �Ϲ������� �� ������ ���������� �̸� �����ϵ� ����� ����ϴ� ��� �����մϴ�.

#include <iostream>

using namespace std;

class Circle {

public:
	Circle() : x(0), y(0), radius(0) {};
	Circle(int xval, int yval, int r){
		x = xval;
		y = yval;
		r = radius;
	}


	void setRadius(int r) {
		radius = r;
	}

	int getRadius() const{
		return radius;
	}


	void draw()
	{
		cout << "draw" << endl;
	}
	void move()
	{
		cout << "move" << endl;
	}

private:
	int x, y, radius;

};

int main()
{

	int choice;
	cout << "� ?";
	cin >> choice;

// unique_ptr<Circle[]> arr(new Circle[choice]);

	Circle * arr = new Circle[choice];



	Circle * p1 = new Circle;
	const Circle * p2 = new Circle;
	Circle * const p3 = new Circle;

	arr[0] = *p1;
	arr[1] = *p2;
	arr[2] = *p3;


	p1->draw();
	// p2->setRadius(40);
	// p2->draw();
	cout << p2->getRadius() << endl;

	p3->setRadius(50);
	cout << p3->getRadius() << endl;

	arr[0].draw();
	arr[1].draw();


	arr[1].setRadius(40);
	cout << arr[1].getRadius() << endl;

	arr[2].setRadius(50);
	cout << arr[2].getRadius() << endl;
	

	



	

	delete[] arr;
	delete p1;
	delete p2;
	delete p3;

	return 0;


}
