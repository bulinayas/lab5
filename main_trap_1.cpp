#include <iostream>
#include <math.h>
#include<fstream>

using namespace std;


double func(double x) { return (exp(-1/pow(x,2))/pow(x,2)); }

double I(double a, double b, int N) {
	double y=0, dy;
	dy = (b - a) / N;
	y += func(a) + func(b);

	for (int i = 1; i < N; i++) { y += 2 * (func(a+ dy * i)); }
	
	return (((b - a) / (2 * N)) * y); 
}

int Runge(double a, double b, int n,double eps0,double Q=1./3., int i=2) {
	double eps;
	eps = Q*abs(I(a+eps0, b, i*n)- I(a + eps0, b, n));
	while ((int)(eps * 10000) >=(int)(eps0*10000)) {
		n *= i;
		eps = Q * abs(I(a + eps0, b, i * n) - I(a + eps0, b, n));
	}
	return n;
}


int main() {
	ofstream fout;
	fout.open("ans1.dat");
	int n=1;
	double a=0, b=1.5,eps0=0.0001,In,eps;

		n=Runge(a, b, n, eps0);

		eps = 1. / 3 * abs(I(a + eps0, b, 2 * n) - I(a + eps0, b, n));
		In = I(a + eps0, b, n)+eps;

		fout<<In<<" "<<eps;
		fout.close();
}