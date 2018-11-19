#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool checkdivergence(double a1, double a2, double a3)
{
	if (abs(a2 + a3 / a1) < 1)
		return true;
	else
		return false;
}

double f1(double x2, double x3)
{
	return (7 - x2 - x3) / 3;
}

double f2(double x1, double x3)
{
	return (4 - 2*x3 - x1) / 3;
}

double f3(double x2)
{
	return (5 - 2 * x2) / 5;
}

double GaussJacobi(double x0, double y0, double z0)
{
	double x, y, z;

	x = f1(y0, z0);
	y = f2(x0, z0);
	z = f3(y0);

	while ((x - x0 < 1e-6) && (y - y0 < 1e-6) && (z - z0 < 1e-6))
	{
		x0 = x;
		y0 = y;
		z0 = z;

		x = f1(y0, z0);
		y = f2(x0,z0);
		z = f3(y0);
	
	}
}

/*
double GaussSeidel(double x0, double y0, double z0)
{
	double x, y, z;

	x = f1(y0, z0);
	y = f2(x0, z0);
	z = f3(y0);

	while ((x - x0 < 1e-6) && (y - y0 < 1e-6) && (z - z0 < 1e-6))
	{
		x0 = x;
		y0 = y;
		z0 = z;

		x = f1(y0, z0);
		y = f2(x0, z0);
		z = f3(y0);

	}
}
*/
int main() {







}