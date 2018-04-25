#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main (){
	ll n,base;

	cin >> n >> base;


	if(n ==  0){
		cout << 0 << endl;
	}else if(n == 1){
		cout << base << endl;
	}else {
		ll resp;

		resp = base + (base-n+1);
		
		resp  = resp * (n);
		resp /= 2;

		cout << resp << endl;

	}


	return 0;
}