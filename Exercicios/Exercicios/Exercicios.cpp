// Exercicios.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double function(double x)
{
	return exp(x) - x * x + 3 * x - 2;
}

double function2(double x)
{
	return (x * x) - x - 1.2;
}

double function3(double x)
{
	return 3 * x + sin(x) - exp(x);
}

double f4(double x)
{
	return (x * x) - x - 0.2;
}

double diff4(double x)
{
	return 2 * x - 1;
}

double diff(double x)
{
	return exp(x) - (2 * x) + 3;
}

double NewtonMethod(double xo,double e)
{
	double x;

	x = xo - (function(xo) / diff(xo));

	while (abs(xo - x) > e)
	{
		xo = x;
		x = xo - (function(xo) / diff(xo));
	}

	return x;
}

double BissectionMethod(double a, double b, double e)
{
	double n ;
	int step = 0;

	while (abs(b-a) >= e)
	{
		n = (b + a) / 2;

		if (function2(a)*function2(n) <= 0)
		{
			b = n;
		}
		else
		{
			a = n;
		}

		step++;
	}
	cout << step << endl;
	return n;
}

double corda(double a, double b, double n)
{
	double x;
	double i = 0;
	double x3 = 0;

	while (i < n)
	{

		x = (a*function3(b) - b * function3(a)) / (function3(b) - function3(a));
		cout << i << ": "<< x << endl;

		if (function3(x)*function3(a) <= 0)
		{
			b = x;
		}
		else
		{
			a = x;
		}

		if (i == 2)
			x3 = x;

		i++;
	}

	cout << " dif: " << abs(x - x3) << endl;
	return x;

}

double PicardMethod(double xo, double e)
{
	int flag;
	double x = 0;

	if (abs(diff4(x)) < 1)
		flag = 0;
	else
	{
		cout << "error";
		exit(1);
	}
	
	int i = 0;


	if (flag == 0)
	{
		x = f4(xo);

		while (abs(xo - x) >= e)
		{
			xo = x;
			x = f4(xo);
			
			cout << x << endl;
		}
	}

	return x;

}

int main()
{
	int flag;

	cout << "1.Ex3" << endl;
	cout << "2.Ex4" << endl;
	cout << "3.Ex5" << endl;
	cout << "4.Ex6" << endl;

	cin >> flag;

	switch (flag)
	{
	case 1:
	{
		double e1 = 5 * pow(10, -4);
		cout << "Value: " << NewtonMethod(0.1, e1);
		break;
	}
	case 2:
	{
		double e2 = pow(10, -1);
		double e3 = pow(10, -7);

		cout << "Value: " << BissectionMethod(1,2, 0.1);
		//cout << "Value: " << BissectionMethod(1, 2, e3);
		break;
	}
	case 3:
	{
		double e4 = pow(10, -3);
		cout << "Value: " << corda(0,1, 4);
		break;
	}
	case 4:
	{
		double e5 = pow(10, -7);
		cout << "Value: " << PicardMethod(0, e5);
		break;
	}
	}
	

    return 0;
}

