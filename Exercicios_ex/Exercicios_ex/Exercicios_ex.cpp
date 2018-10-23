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


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

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
	}
    return 0;
}

