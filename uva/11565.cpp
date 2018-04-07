//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main (){

	int k;
	int A,B,C;
	int x,y,z;

	cin >> k;

	while(k>0){

		cin >> A >> B >> C; 

		x = y = z = 1;

		for (x = 1; x < 23; x++){
			for (y = 1; y < 23; y++){
				for (z = 1; z < 23; z++){
					if(x + y + z == A && x*y*z == B && (x*x)+(y*y)+(z*z) == C){
						cout <<  x << " " << y << " " << z << '\n';
						y=999;
						x=999;
						z=999;
						break;
					}

				}
			}
		}

		if(x != 1000){
			cout << "No solution.\n";
		}


		k--;
	}


}