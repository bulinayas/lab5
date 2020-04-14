#include <iostream>
#include <math.h>
#include<fstream>

using namespace std;


double func(double x) { return (exp(-1 / pow(x, 2)) / pow(x, 2)); }

double I(double a, double b, int n) {
	double dy= (b - a) / n;
	double k1 = 0, k2 = 0;

	for (int i = 1; i < n; i += 2) {
		k1 += func(a + i * dy);
	}

	for (int i = 2; i < n; i += 2) {
		k2 += func(a + i * dy);
	}
	return ((dy / 3) * (func(a) + 4 * k1 + 2 * k2+ func(b)));
}

int Runge(double a, double b, int n, double eps0, double Q = 1. / 3., int i = 2) {
	double eps;
	eps = Q * abs(I(a + eps0, b, i * n) - I(a + eps0, b, n));
	while ((int)(eps * 10000) >= (int)(eps0 * 10000)) {
		n *= i;
		eps = Q * abs(I(a + eps0, b, i * n) - I(a + eps0, b, n));
	}
	return n;
}


int main() {
	ofstream fout;
	fout.open("ans2.dat");
	int n = 1;
	double a = 0, b = 1.5, eps0 = 0.0001, In, eps;

	n = Runge(a, b, n, eps0);

	eps = 1. / 3 * abs(I(a + eps0, b, 2 * n) - I(a + eps0, b, n));
	In = I(a + eps0, b, n) + eps;

	fout << In << " " << eps;
	fout.close();
}
