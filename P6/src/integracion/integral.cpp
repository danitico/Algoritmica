#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;
double integral( double (*func)(double), double init, double end){
	double h=0.01, areaE=0, areaD=0;
	for(; init<end; init=init+h){
		if(func(init)>=func(init+h)){
			areaE=h*func(init)+areaE;
			areaD=h*func(init+h)+areaD;
		}
		else{
			areaE=h*func(init+h)+areaE;
			areaD=h*func(init)+areaD;
		}
	}
	double areaintegral=(areaE+areaD)/2;
	return areaintegral;
}
////
int test();//indica que la funcion test esta mas abajo
int main(){
		test();
		cout<<"Correcto"<<endl;
		system("pause");
		return 0;
}
//funcion de test
double const_f(double x){return x;}

int test(){
	assert(fabs( integral(const_f,0,1)-0.5)<1e-2);
	assert(fabs( integral(sin,0,1)-0.459656)<1e-2);
	assert(fabs( integral(cos,0,1)-0.841394)<1e-2);
	assert(fabs( integral(exp,0,2)-6.3891)<1e-2);
	assert(fabs( integral(log,1,2)-0.38629)<1e-2);
	return 0;
}
