// teste1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double function1(double x)
{
	return pow(x, 3) - 10 * sin(x) + 5.7;
}

double function2(double x, double a, double b, double c)
{
	return a * pow(x, 7) + b * x - c;
}

double Bissection(double x0, double xf, int n)
{
	double x;

	while (n > 0)
	{
		x = (x0 + xf) / 2;

		if (function1(x0)*function1(x) <= 0)
			xf = x;
		else
			x0 = x;

		cout << "x0" << x0 << endl;
		cout << "xf" << xf << endl;

		n--;
	}

	return x;
}

double Corda(double x0, double xf, int n, double a, double b, double c)
{
	double x;

	while (n > 0)
	{
		x = (x0*function2(xf, a, b, c) - function2(x0, a, b, c)*xf) / (function2(xf, a, b, c) - function2(x0, a, b, c));

		if (function2(x, a, b, c)*function2(x0, a, b, c) < 0)
			xf = x;
		else
			x0 = x;

		cout << "x0" << x0 << endl;
		cout << "xf" << xf << endl;

		n--;
	}

	return x;
}


int main()
{
	//cout << Bissection(1.5, 4.2, 2) << endl;
	cout << Corda(1,1.2,3,1,-0.5,1) << endl;

    return 0;
}

