#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y)
{
	return exp(y - x);

}

double h(double i, double f, double n)
{
	return abs(f - i) / n;
}

double sum0(double xo, double xf, double yo, double yf)
{
	double sum;
	
	sum = f(xo, yo) + f(xo, yf) + f(xf, yo) + f(xf, yf);

	return sum;
}

double sum1(double xo, double xf, double yo, double yf)
{
	double sum;

	sum = f(xf/2, yo) + f(xf/2, yf) + f(xo, yf/2) + f(xf, yf/2);

	return sum;
}

double sum2(double xo, double xf, double yo, double yf)
{
	return f(xf /2, yf/2);
}


double Simp(double xo, double xf, double yo, double yf)
{
	double sum, hx, hy;

	hx = h(xo, xf, 2);
	hy = h(yo, yf, 2);

	sum = (hx * hy) / 9;
	return sum * (sum0(xo, xf, yo, yf) + 4*sum1(xo, xf, yo, yf) + 16*sum2(xo, xf, yo, yf));


}

double CubS(double xo, double xf, double yo, double yf, double n)
{
	double hx, hy, result;
	result = 0;

	hx = h(xo, xf, n);
	hy = h(yo, yf, n);


	for (int i = 0; i < (n / 2); i++) {
		for (int j = 0; j < (n / 2); j++) {
			result += Simp(xo + 2 * i*hx, xo + 2 * (i + 1)*hx, yo + 2 * j*hy, yo + 2 * (j + 1)*hy);
		}
	}

	return result;

}
int main()
{
	
	cout << CubS(0,0.5,0,0.5,2);
	return 0;
}