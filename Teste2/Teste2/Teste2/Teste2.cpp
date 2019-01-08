// Teste2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double Clinha(double C, double b, double T)
{
	return -exp( - (b / (T + 273)))  *C;
}

double Tlinha(double a, double b, double T, double C)
{
	return a * exp(-b / (T + 273))*C - b * (T - 20);
}

double function(double x )
{
	return -5 * cos(x) + sin(x) + 10;
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
void AureaMethod(double x1, double x2, bool minimum, int n , double &x, double &y)
{
	double B = (sqrt(5) - 1) / 2;
	double A = pow(B, 2);
	double x3, x4, func3, func4;
	x3 = x4 = 0;

	while (n > 0)
	{
		cout << "x1: " << x1 << endl;
		cout << "x2: " << x2 << endl;
		cout << "f(x1): " << function(x1) << endl;
		cout << "f(x2): " << function(x2) << endl;

		x3 = x1 + A * +(x2 - x1);
		x4 = x1 + B * (x2 - x1);

		func3 = function(x3);
		func4 = function(x4);

		if (minimum)
		{
			if (func3 < func4)
				x2 = x4;
			else
				x1 = x3;
		}
		else
		{
			if (func3 > func4)
				x2 = x4;
			else
				x1 = x3;
		}

	
		cout << "x3: " << x3 << endl;
		cout << "x4: " << x4 << endl;
		cout << "f(x3): " << function(x3) << endl;
		cout << "f(x4): " << function(x4) << endl;

		n--;
		
	}
	cout << "amplitude " << abs(x1 - x2) << endl;

		if (minimum)
			x = x2;
		else
			x = x1;

		y = function(x);

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

void EulerMethod(double t0, double C0, double T0, double h, double n, double a, double b, double &tr)
{
	double t, C, T;
	t = C = T = 0;

	while (n > 0)
	{
		t = t + h;
		T = T0 + h * Tlinha(a, b, T0, C0);
		C = C0 + h * Clinha(C0, b, T0);

		cout << "t" << t << endl;
		cout << "C" << C << endl;
		cout << "T" << T << endl;

		t0 = t;
		C0 = C;
		T0 = T;
		n--;
	}

	tr = T;
}

double dy1(double t, double C, double T, double h, double b)
{
	return h * Clinha(C, b, T);
}

double dk1(double t, double C, double T, double h, double b, double a)
{
	return h * Tlinha(a, b, T, C);
}

double dy2(double t, double C, double T, double h, double b, double a)
{
	return h * Clinha(C + (dy1(t, C, T, h, b) / 2), b, T + (dk1(t, C, T, h, b, a) / 2));
}

double dk2(double t, double C, double T, double h, double b, double a)
{
	return h * Tlinha(a,b, T + (dk1(t, C, T, h, b, a) / 2),C + (dy1(t, C, T, h, b) / 2));
}

double dy3(double t, double C, double T, double h, double b, double a)
{
	return h * Clinha(C + (dy2(t, C, T, h, b,a) / 2), b, T + (dk2(t, C, T, h, b, a) / 2));
}

double dk3(double t, double C, double T, double h, double b, double a)
{
	return h * Tlinha(a,b, T + (dk2(t, C, T, h, b, a) / 2),C + (dy2(t, C, T, h, b,a) / 2));
}

double dy4(double t, double C, double T, double h, double b, double a)
{
	return h * Clinha(C + dy3(t, C, T, h, b,a), b, T + dk3(t, C, T, h, b, a));
}

double dk4(double t, double C, double T, double h, double b, double a)
{
	return h * Tlinha(a, b, T + dk3(t, C, T, h, b, a), C + dy3(t, C, T, h, b, a) );
}

void RK4(double t0, double C0, double T0, double n, double h, double a, double b)
{
	double t, C, T;
	t = C = T = 0;

	while (n > 0)
	{
		t = t0 + h;
		C = C0 + (dy1(t0,C0,T0,h,b) / 6) + ( dy2(t0, C0, T0, h, b,a)/3) +( dy3(t0, C0, T0, h, b, a)/3)+(dy4(t0, C0, T0, h, b, a)/6);
		T = T0 + (dk1(t0, C0, T0, h, b, a) / 6) + (dk2(t0, C0, T0, h, b, a) / 3) + (dk3(t0, C0, T0, h, b, a) / 3) + (dk4(t0, C0, T0, h, b, a) / 6);

		cout << "t" << t << endl;
		cout << "C" << C << endl;
		cout << "T" << T << endl;

		t0 = t;
		C0 = C;
		T0 = T;
		n--;
	}
}

int main()
{
	//double x, y = 0;

	//AureaMethod(2, 4, false, 3, x, y);

	//Gradient(1, 2, 0.5, 2);

	double s, sl, sll;
	double t;

	EulerMethod(0, 2.5, 25, 0.25, 2, 30, 0.5,t);
	s = t;
	cout << "valor1 " << s << endl;
	EulerMethod(0, 2.5, 25, 0.125, 2, 30, 0.5,t);
	sl = t;
	cout << "valor2 " << sl << endl;
	EulerMethod(0, 2.5, 25, 0.0625, 2, 30, 0.5, t);
	sll = t;
	cout << "valor3 " << sll << endl;

	cout << "quocient " << (sl - s) / (sll - sl) << endl;
	cout << "erro" << ((sll - sl) / 15) << endl;



	//RK4(0, 2.5, 25, 2, 0.25, 30, 0.5);
    return 0;
}

