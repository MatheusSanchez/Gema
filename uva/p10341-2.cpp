//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

#define error 0.0000001


using namespace std;



int p,q,r,s,t,u;

double f(double x){
	return p*pow(M_E,-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x,2) + u;	
}

double g(double lo, double hi){

	while(hi - lo > error){
		double center = (lo + hi)/2;

		if(f(lo) * f(center) <	0){
			hi = center;
		}else{
			lo = center;
		}
	}
		

	return (lo + hi)/2;	

}


int main (){
	ios :: sync_with_stdio(false); 
	while(cin >> p >> q >> r >> s >> t >> u){
		

		 if((f(0) > 0 && f(1) > 0) || (f(0) < 0 && f(1) < 0)) {
	     	 printf("No solution\n");
	     }else{
	     	printf("%.4lf\n", g(0,1));
	     } 
	   
	}
		

}