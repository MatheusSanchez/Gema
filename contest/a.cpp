#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll vai (ll n){

	if(n%10 == 0){
		return (n/10);
	}else{
		//cout << "EAE" << endl;
		return n-1;
	}

}

int main (){

	ll n,k;

	cin >> n >> k;

	while(k>0){
		//cout << "EAE";

		n = vai(n);
		k--;
	}	


	cout << n << endl;

	return 0;	
}