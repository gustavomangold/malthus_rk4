#include <stdio.h>
#include <math.h>

double func (double x) {      //função dV/dt, a taxa de crescimento do volume de celulas
	double a0 = 0.0089;

	return a0*x;

}

double funcA (double t) {     //função solução
	double x0 = 904.8;
	double a1 = 0.0089;

	return x0*exp(a1*t); 

}

int main () {

double j1, j2, j3, j4, k1, k2, p1, q1, a1, a2, h, V00, Ve0, Ve, V2, V20, V40, t, tmax;
double a = 0.0089; //taxa alpha de crescimento
V00 = 904.8;       //volume inicial de celulas
h=0.05;
t=0;
tmax = 300;
Ve0=V00;	//variável do volume de células para euler
V20 = V00;	//para rk2
V40 = V00; 	//para rk4


do {

 while (t<=tmax) {	
	
	//para imprimir resultado dos métodos, comentar os não desejados
	
	//euler

	Ve=(func(Ve0))*h+Ve0;
	Ve0=Ve;
	//printf("%lf %.25lf\n", t, Ve);

	//rk2

	a2 = 2./3;
	a1 = 1 - a2;
	p1 = 0.5/a2;
	q1 = 0.5/a2;

	k1 = func(V20);
	k2 = func(V20+q1*h*k1);
	V2 = V20 + (a1*k1 + a2*k2)*h;
	V20 = V2;
	//printf("%lf %.25lf\n", t, V2);

	// rk4

	j1 = h*func(V40);
	j2 = h*func(V40+j1/2);
     	j3 = h*func(V40+j2/2);
        j4 = h*func(V40+j3);
        V40 = V40 + (j1/6+j2/3+j3/3+j4/6);

	//printf("%lf %.25lf\n", t, V40); 
	
	t = t+h;

  }

	//parte do código que calcula o erro absoluto, variando o intervalo de tempo

	printf("%lf %.25lf %.25lf %.25lf\n", h, fabs(funcA(t) - Ve0), fabs(funcA(t) - V20), fabs(funcA(t) - V40));
  	h = h+0.001;
   	t = 0;
    	Ve0 = V00;
	V20 = V00;	
 	V40 = V00;

}  while (h<=1);




return 0;
}
