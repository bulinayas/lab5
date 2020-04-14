import math as m

def func(x):
    return (m.exp(-1/(x**2))/(x**2))

def I(a, b, N):
    y=0
    dy = (b - a) / N
    y += func(a) + func(b)

    for i in range(1,N,1):
        y += 2 * (func(a+ dy * i))
	
    return (((b - a) / (2 * N)) * y)

def Runge(a, b, n, eps0,Q=1./3.,i=2):
    eps = Q*abs(I(a+eps0, b, i*n)- I(a + eps0, b, n))
    while (int(eps * 10000) >= int(eps0*10000)):
        n *= i
        eps = Q*abs(I(a+eps0, b, i*n)- I(a + eps0, b, n))
    return n


n=1
a=0
b=1.5
eps0=0.0001

n=Runge(a, b, n, eps0)

eps = 1. / 3 * abs(I(a + eps0, b, 2 * n) - I(a + eps0, b, n))
In = I(a + eps0, b, n)+eps

print(In," ",eps)
