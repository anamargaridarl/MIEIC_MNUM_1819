
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x, double y, double z)
{
	return z * y + x;
}

double g(double x, double y, double z)
{
	return z * x + y;
}

/////////////////////////////////////////////////////////////////////////////

double pk1(double x, double y, double z, double h)
{
	return h * g(x, y, z);
}
/////////////////
double py1(double x, double y, double z, double h)
{
	return h * f(x, y, z);
}
/////////////////
double pk2(double x, double y, double z, double h)
{
	return h * g(x + (h / 2), y + (py1(x, y, z, h) / 2), z + (pk1(x, y, z, h) / 2));
}
/////////////////
double py2(double x, double y, double z, double h)
{
	return h * f(x + (h / 2), y + (py1(x, y, z, h) / 2), z + (pk1(x, y, z, h) / 2));
}
/////////////////
double pk3(double x, double y, double z, double h)
{
	return h * g(x + (h / 2), y + (py2(x, y, z, h) / 2), z + (pk2(x, y, z, h) / 2));
}
/////////////////
double py3(double x, double y, double z, double h)
{
	return h * f(x + (h / 2), y + (py2(x, y, z, h) / 2), z + (pk2(x, y, z, h) / 2));
}
/////////////////
double pk4(double x, double y, double z, double h)
{
	return h * g(x + h, y + py3(x, y, z, h), z + pk3(x, y, z, h));
}
/////////////////
double py4(double x, double y, double z, double h)
{
	return h * f(x + h, y + py3(x, y, z, h), z + pk3(x, y, z, h));
}

/////////////////////////////////////////////////////////////////////////////


void system(double x0, double y0, double z0, double h, double xf, double &ry, double &rz)
{
	double x, y,z;

	while (x0 <= xf)
	{
		x = x0 + h;
		y = y0 + (py1(h, x0, y0,z0) / 6) + (py2(h, x0, y0,z0) / 3) + (py3(h, x0, y0,z0) / 3) + (py4(h, x0, y0,z0) / 6);
		z = z0 + (pk1(h, x0, y0, z0) / 6) + (pk2(h, x0, y0, z0) / 3) + (pk3(h, x0, y0, z0) / 3) + (pk4(h, x0, y0, z0) / 6);

		x0 = x;
		y0 = y;
		z0 = z;

		cout << x0 << endl;
		cout << y0 << endl;
		cout << z0 << endl;
	}

	ry = y0;
	rz = z0;

}

double quocient(double s, double sl, double sll)
{
	return (sl - s) / (sll - sl);
}

int main()
{
	double sz, slz, sllz;
	double sy, sly, slly;
	double const e = 0.001;

	double ry, rz;

	cout << "Systems" << endl;
	

		system(0, 1,1, 0.1, 0.4999999,ry,rz);
		cout << "y " << ry << endl;
		cout << "z " << rz << endl;

		sy = ry;
		sz = rz;

		system(0, 1, 1, 0.05, 0.4999999,ry,rz);
		cout << "yl " << ry << endl;
		cout << "zl " << rz << endl;

		sly = ry;
		slz = rz;

		system(0, 1, 1, 0.025, 0.4999999, ry, rz);
		cout << "yll " << ry << endl;
		cout << "zll " << rz << endl;

		slly = ry;
		sllz = rz;

		cout << "qy " << quocient(sy, sly,slly) << endl;
		cout << "qz " << quocient(sz,sllz, slz) << endl;

		return 0;
}