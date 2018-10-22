// TP5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double dy(double x, double y)
{
	return x*x + y * y;
}

double EulerMethod(double x0, double y0, double h, double xf)
{
	double x, y;

	while (x0 <= xf)
	{
		x = x0 + h;
		y = y0 + h * dy(x0, y0);


		x0 = x;
		y0 = y;
	}

	return y0;
}

double quocient(double s, double sl, double sll)
{
	return (sl - s) / (sll - sl);
}

double eulerError(double sll, double sl)
{
	return sll - sl;
}
int main()
{

	int flag = 0;
	double const e = 0.001;

	cout << "1. Euler" << endl;
	cout << "2. Newton Method" << endl;
	cin >> flag;

	switch (flag)
	{
	case 1:
	{
		//double x0, y0, xf, h;
		double s, sl, sll;

		s = EulerMethod(0, 0, 0.1, 1.3999);
		cout << "s " <<s <<endl;

		sl = EulerMethod(0, 0, 0.05, 1.3999);
		cout <<"sl " << sl<<endl;


		sll = EulerMethod(0, 0 ,0.025 , 1.3999);
		cout << "sll " << sll << endl;

		cout <<"q "<< quocient(s, sl, sll)<< endl;
		cout <<"e "<< eulerError(sll, sl)<< endl;

		break;
	}
	/*case 2:
	{
		double a;
		cout << "Enter value to start:" << endl;
		cin >> a;

		cout << setprecision(3) << NewtonMethod(a, e);

	}*/
	default:
	{
		cout << "error" << endl;
		break;
	}

	}
	return 0;
}

