// Exercicios_ex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
	return (x - 3.6) + pow((cos(x + 1.2)), 3);
}

double f2(double x, double m, double R)
{
	return pow(x, m) - R;
}

double f3(double x)
{
	return pow(x,3)+2*x*x +10*x -17;
}

double f4(double x, double y)
{
	return y - log(x - 1);
}

double f5(double x, double y,double a, double r)
{
	return y*y + pow(x - a, 2) - (r * r);
}
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

double dx4(double x)
{
	return -(1 / (x - 1));
}

double dy4()
{
	return 1;
}

double dx5(double x, double a)
{
	return 2 * (x - a);
}

double dy5(double y)
{
	return 2 * y;
}

double diff(double x)
{
	return 1 - 3 * pow(cos(x + 1.2), 2)*sin(x + 1.2);
}
double diff2(double x, double m)
{
	return m*pow(x,m-1);
}

double diff3(double x)
{
	return 3 * x *x + 4 * x + 10;
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

double Newton(double xo, double n)
{
	double x;
	int i = 0;


	for (int i = 0; i < n; i++)
	{
		x = xo - (f(xo) / diff(xo));
		xo = x;

	}

	return x;
	
}

double Newton2(double xo,double m, double R, double n)
{
	double x;
	int i = 0;


	for (int i = 0; i < n; i++)
	{
		x = xo - (f2(xo,m,R) / diff2(xo,m));
		xo = x;

	}

	return x;

}

double Newton3(double xo, double n)
{
	double x;

	for (int i = 0; i < n; i++)
	{
		x = xo - (f3(xo) / diff3(xo));
		xo = x;
		cout << xo << endl;
	}

	return x;

}

void sistemas(double xo, double yo,double a, double r, int n)
{
	double x, y;

	for (int i = 0; i < n; i++)
	{
		x = xo - ((f4(xo, yo)*dy5(yo) - f5(xo, yo, a, r)*dy4()) / (dx4(xo)*dy5(yo) - dx5(xo, a)*dy4()));
		y = yo - ((f5(xo, yo, a, r)*dx4(xo) - f4(xo, yo)*dx5(xo, a)) / (dx4(xo)*dy5(yo) - dx5(xo, a)*dy4()));

		xo = x;
		yo = y;

		cout << i + 1 << "x: " << x << "y: " << y << endl;
	}
}

int main()
{
	int flag = 0;

	cout << "1.Ex1" << endl; //p1 teste 2017

	cin >> flag;

	switch (flag)
	{
	case 1:
	{
		cout << Newton(0.5,1) << endl;
	}
	case 2:
	{
		cout << Newton3(0, 3) << endl;
	}
	case 3:
	{
		sistemas(1.5, 1.3, 3, 2,3);
	}
	}
    return 0;
}

