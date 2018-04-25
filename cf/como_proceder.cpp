#include <bits/stdc++.h>
#define ll long long
#define N 1000000

using namespace std;

int main (){


	ll k,l,r;
	ll soma = 0;

	ll a_soma[N+1];

	cin >> k;


	a_soma[0];
	

	for (int i = 1; i <= k; ++i){
		scanf("%lld",&a_soma[i]);
		a_soma[i] = (a_soma[i] + a_soma[i-1]);
	}

	cin >> k;

	while(k--){

		cin >> l;
		cin >> r;	
		cout << a_soma[r] - a_soma[l-1] << endl;

		
	}


}