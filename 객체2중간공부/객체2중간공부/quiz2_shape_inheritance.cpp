#include "pch.h"
#include <iostream>


using namespace std;

class Shape
{

public:
	Shape() {};
	
	void setX(int X1)
	{
		X = X1;
	}
	
	void setY(int Y1)
	{
		Y = Y1;
	}

	float getArea();
	
protected:
	int X;
	int Y;

};

class Rect : public Shape
{
public:
	
	Rect() {};
	
	void setWidth(int w)
	{
		Width = w;
	}

	void setHeight(int h)
	{
		Height = h;
	}

	float getArea()
	{
		return Width * Height;
	}

protected:

	int Width;
	int Height;

};

class Circle : public Shape
{
public:
	Circle() {};
	
	void setRadius(int r)
	{
		Radius = r;
	}

	float getArea()
	{
		return Radius * Radius * 3.14;
	}

protected:
	int Radius;
};


int main()
{
	Rect r1;
	Circle c1;

	cout << "사각형의 면적 :  " << r1.getArea() << endl;
	cout << "원의 면적 : " << c1.getArea() << endl;

	return 0;
}