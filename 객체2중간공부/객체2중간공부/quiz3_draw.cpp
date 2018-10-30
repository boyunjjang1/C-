// pch.cpp: �̸� �����ϵ� ����� �ش��ϴ� �ҽ� �����Դϴ�. �����Ϸ��� �������� �ʿ��մϴ�.

#include "pch.h"

// �Ϲ������� �� ������ ���������� �̸� �����ϵ� ����� ����ϴ� ��� �����մϴ�.

#include <iostream>
#include <Windows.h>

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
	Rect(int x, int y, int width, int height)
	{
		X = x;
		Y = y;
		Width = width;
		Height = height;
	}

	void setWidth(int w)
	{
		Width = w;
	 }
	
	void setHeight(int h)
	{
		Height = h;
	}


		void draw()
		{
			HDC hdc = GetDC(GetConsoleWindow());
			Rectangle(hdc, X, Y, X + Width, Y + Height);
		}
	

protected:
	int Width;
	int Height;
};

class ColoredRect : public Rect
{

public:
	
	ColoredRect() {};

	ColoredRect(int x, int y, int width, int height, int b, int g, int r)
	{
		X = x;
		Y = y;
		Width = width;
		Height = height;
		blue = b;
		green = g;
		red = r;
	}
	
	void setBlue(int b)
	{
		blue = b;
	}

	void setGreen(int g)
	{
		green = g;
	}

	void setRed(int r)
	{ 
		red = r;
	}

	void draw()
	{
		HDC hdc = GetDC(GetConsoleWindow());
		SelectObject(hdc, GetStockObject(DC_BRUSH));
		SetDCBrushColor(hdc, RGB(red, green, blue));
		Rectangle(hdc, X, Y, X + Width, Y + Height);

	}

protected:
	int blue;
	int green;
	int red;


};


int main()
{


	Rect r1(200, 200, 80, 80);
	ColoredRect r2(300, 300, 80, 80, 255, 0, 0);

	r1.draw();
	r2.draw();


	return 0;
}