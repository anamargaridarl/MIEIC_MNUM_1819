// Exame 2017.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double ncalc(double x0, double xf, double h)
{
	return (xf - x0) / h;
}

double function1(double x, double k)
{
	return sqrt(1 + pow(k*exp(k*x), 2));
}

double Trapezio(double x0, double xf, double h, double k)
{
	double result;
	int n;
	
	n= ncalc(x0, xf, h);
	result = function1(x0,k) + function1(xf,k);
	
	for (int i = 1; i < n; i++)
	{
		result += 2 * function1(x0 + i * h,k);
	}
	
	result = (h / 2) * result;

	return result;
}

double Simpson(double x0, double xf, double k, double h)
{
	int n;
	double result;

	n = ncalc(x0, xf, h);
	result = function1(x0, k) + function1(xf, k);

	for (int i = 1; i < n; i++)
	{
		if (i % 2 != 0)
			result += 4 * function1(x0 + i * h, k);
		else
			result += 2 * function1(x0 + i * h, k);
	}

	result = (h / 3) * result;

	return result;

}

double function2(double x)
{
	return exp(x) - x - 5;
}

double diff2(double x)
{
	return exp(x) - 1;
}

double Newton(double x0, int n)
{
	double x = 0;

	cout << "x0: " << x0 << endl;

	while (n > 0)
	{
		x = x0 - function2(x) / diff2(x0);
		x0 = x;

		cout << "x0: " << x0 << endl;

		n--;
	}

	return x0;
}

double gx(double x)
{
	return log(5 + x);
}

double PicardoPeano(double x0, double xf, int n)
{
	cout << "picardpeano" << endl;
	double x;

	while (n > 0)
	{
		x = gx(x0);
		x0 = x;

		cout << "x0: " << x0 << endl;
		n--;

	}

	return x0;
}

double function2(double x, double y)
{
	return 6 * x*x - x * y + 12 * y + y * y - 8 * x;
}

double devFunctionX(double x, double y)
{
	return -y + 12 * x - 8;
}

double devFunctionY(double x, double y)
{
	return 2 * y - x + 12;
}
void Gradient(double x0, double y0, double h, double n) {

	cout << "\tw(x,y): " << function2(x0, y0) << endl;

	double x, y;
	while (n > 0) {
		x = x0 - h * devFunctionX(x0, y0);
		y = y0 - h * devFunctionY(x0, y0);

		cout << devFunctionX(x0, y0) << endl;
		cout << devFunctionY(x0, y0) << endl;

		if (function2(x, y) < function2(x0, y0)) {
			x0 = x;
			y0 = y;
			h *= 2;
		}
		else {
			h /= 2;
		}

		cout << "x: " << x << "\ty: " << y << "\tw(x,y): " << function2(x, y) << endl;
		n--;
	}
}


int main()
{
	//cout << Trapezio(0, 1, 0.03125, 2.5) << endl;
	//cout << Simpson(0, 1, 2.5, 0.125) << endl;

	cout << Newton(1,10) << endl;
	cout << PicardoPeano(1, 3, 10) << endl;
    return 0;
}

