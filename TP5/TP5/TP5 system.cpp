
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x, double y, double z)
{
	//return z * y + x;
	return z;
}

double g(double x, double y, double z)
{
	//return z * x + y;
	return x + 2 * y - 3 * z;
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


void systemRk4(double x0, double y0, double z0, double h, double xf, double &ry, double &rz)
{
	double x, y,z;

	ry = 0;
	rz = 0;


	while (x0 <= xf)
	{
		x = x0 + h;
		y = y0 + (py1(x0, y0,z0,h)/6) + (py2(x0, y0,z0,h) / 3) + (py3(x0, y0,z0,h)/3) + (py4(x0, y0,z0,h)/6);
		z = z0 + (pk1(x0, y0, z0,h) / 6) + (pk2(x0, y0, z0,h)/3) + (pk3(x0, y0, z0,h) / 3) + (pk4(x0, y0, z0,h) / 6);

		x0 = x;
		y0 = y;
		z0 = z;

		/*
		cout << x0 << endl;
		cout << y0 << endl;
		cout << z0 << endl;*/
	}

	cout << x0 << endl;
	ry = y0;
	rz = z0;

}


void systemEuler(double x0, double y0, double z0, double h, double xf, double &ry, double &rz)
{
	double x, y, z;

	ry = 0;
	rz = 0;


	while (x0 <= xf)
	{
		x = x0 + h;
		y = y0 + h * f(x0,y0,z0);
		z = z0 + h * g(x0,y0,z0);

		x0 = x;
		y0 = y;
		z0 = z;

		/*
		cout << x0 << endl;
		cout << y0 << endl;
		cout << z0 << endl;*/
	}

	ry = y0;
	rz = z0;
}

void systemRk2(double x0, double y0, double z0, double h, double xf, double &ry, double &rz)
{
	double x, y, z;

	while (x0 <= xf)
	{
		x = x0 + h;
		y = y0 + h * f(x0 + h / 2, y0 + (h / 2)*f(x0, y0, z0), z0 + (h / 2)*g(x0, y0, z0));
		z = z0 + h * g(x0 + h / 2, y0 + (h / 2)*f(x0, y0, z0), z0 + (h / 2)*g(x0, y0, z0));

		x0 = x;
		y0 = y;
		z0 = z;

		/*
		cout << x0 << endl;
		cout << y0 << endl;
		cout << z0 << endl;*/
	}

	ry = y0;
	rz = z0;
}

double quocient(double s, double sl, double sll)
{
	return (sl - s) / (sll - sl);
}

double eulerError(double sll, double sl)
{
	return sll - sl;
}

double Rk2error(double sll, double sl)
{
	return (sll - sl) / 3;
}

double Rk4error(double sll, double sl)
{
	return (sll - sl) / 15;
}


int main()
{
	int flag;
	double sz, slz, sllz;
	double sy, sly, slly;
	double const e = 0.001;

	double ry, rz;

	ry = 0;
	rz = 0;


	cout << "1.Rk4" << endl;
	cout << "2.Rk2" << endl;
	cout << "3.Euler" << endl;

	cin >> flag;

	switch (flag)
	{
	case 1:
	{
		systemRk4(0, 0, 0, 0.0125, 0.4999999, ry, rz);
		cout << "y " << ry << endl;
		cout << endl;
		cout << "z " << rz << endl;

		sy = ry;
		sz = rz;

		cout << endl;
		cout << endl;

		systemRk4(0, 0, 0, 0.00625, 0.4999999, ry, rz);
		cout << "yl " << ry << endl;
		cout << endl;
		cout << "zl " << rz << endl;

		sly = ry;
		slz = rz;

		cout << endl;
		cout << endl;

		systemRk4(0, 0, 0, 0.003125, 0.4999999, ry, rz);
		cout << "yll " << ry << endl;
		cout << endl;
		cout << "zll " << rz << endl;

		slly = ry;
		sllz = rz;

		cout << endl;
		cout << endl;

		cout << "qy " << quocient(sy, sly, slly) << endl;
		cout << endl;
		cout << "qz " << quocient(sz, slz, sllz) << endl;

		cout << endl;
		cout << endl;

		cout << "error y: " << Rk4error(slly, sly) << endl;
		cout << endl;
		cout << "error z: " << Rk4error(sllz, slz) << endl;


		break;
	}
	case 2:
	{
		systemRk2(0, 1, 1, 0.1, 0.4999999, ry, rz);
		cout << "y " << ry << endl;
		cout << "z " << rz << endl;

		sy = ry;
		sz = rz;

		systemRk2(0, 1, 1, 0.05, 0.4999999, ry, rz);
		cout << "yl " << ry << endl;
		cout << "zl " << rz << endl;

		sly = ry;
		slz = rz;

		systemRk2(0, 1, 1, 0.025, 0.4999999, ry, rz);
		cout << "yll " << ry << endl;
		cout << "zll " << rz << endl;

		slly = ry;
		sllz = rz;

		cout << "qy " << quocient(sy, sly, slly) << endl;
		cout << "qz " << quocient(sz, slz, sllz) << endl;

		cout << "error y: " << Rk2error(slly, sly) << endl;
		cout << "error z: " << Rk2error(sllz, slz) << endl;

		break;
	}
	case 3:
	{
		systemEuler(0, 1, 1, 0.1, 0.4999999, ry, rz);
		cout << "y " << ry << endl;
		cout << endl;
		cout << "z " << rz << endl;

		sy = ry;
		sz = rz;
		cout << endl;
		cout << endl;

		systemEuler(0, 1, 1, 0.05, 0.4999999, ry, rz);
		cout << "yl " << ry << endl;
		cout << endl;
		cout << "zl " << rz << endl;

		sly = ry;
		slz = rz;
		cout << endl;
		cout << endl;

		systemEuler(0, 1, 1, 0.025, 0.4999999, ry, rz);
		cout << "yll " << ry << endl;
		cout << endl;
		cout << "zll " << rz << endl;

		slly = ry;
		sllz = rz;
		cout << endl;
		cout << endl;

		cout << "qy " << quocient(sy, sly, slly) << endl;
		cout << endl;
		cout << "qz " << quocient(sz, slz, sllz) << endl;

		cout << endl;
		cout << endl;

		cout << "error y: " << eulerError(slly, sly) << endl;
		cout << endl;
		cout << "error z: " << eulerError(sllz, slz) << endl;

		break;
	}
	}

	

		return 0;
}