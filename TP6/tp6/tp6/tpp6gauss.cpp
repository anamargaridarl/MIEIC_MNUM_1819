#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool checkdivergence(double a1, double a2, double a3)
{
	if (abs((a2 + a3) / a1) < 1)
		return true;
	else
		return false;
}

double f1(double x2, double x3)
{
	return (12 - 1*x2 - 2*x3) /4 ;
}

double f2(double x1, double x3)
{
	return (13 - 2*x1 - 1*x3) / 4;
}

double f3(double x2,double x1)
{
	return (16 - 2*x1 - x2) / 4;
}


void GaussJacobi(double x0, double y0, double z0, double &x, double &y, double &z)
{
	int n = 0;
	x = f1(y0, z0);
	y = f2(x0, z0);
	z = f3(y0,x0);

	while ( abs(x-x0) > 0.01 && abs(y - y0) > 0.01 && abs(z - z0) > 0.01)
	{
		x0 = x;
		y0 = y;
		z0 = z;

		x = f1(y0, z0);
		y = f2(x0,z0);
		z = f3(y0,x0);
		
		cout << "x " << x << endl;
		cout << "y " << y << endl;
		cout << "z " << z << endl;
		n++;
	}
}


void GaussSeidel(double x0, double y0, double z0, double &x, double &y, double &z)
{
	x = f1(y0, z0);
	y = f2(x0, z0);
	z = f3(y0,x0);

	while (abs(x - x0) > 0.01 && abs(y - y0) > 0.01 && abs(z - z0) > 0.01)
	{
		x0 = x;
		y0 = y;
		z0 = z;

		x = f1(y0, z0);
		y = f2(x, z0);
		z = f3(y,x);

	}
}

int main() {
	
	double x = 0;
	double y = 0;
	double z = 0;

	//GaussJacobi(0, 0, 0, x, y, z);
	GaussSeidel(0, 0, 0, x, y, z);

	if (checkdivergence(4, 2, 1) == true)
		cout << "1" << endl;
	if(checkdivergence(1, 3, 1) == true)
		cout << "2 " << endl;
	if (checkdivergence(2, 1, 5) == true)
	cout << "3" << endl;

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;



}