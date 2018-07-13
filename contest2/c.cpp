#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

	ios :: sync_with_stdio(false);

	int n_dorm,n_cart;	

	ll soma = 0, ind = 0,aux;

	vector<ll> dorm;
	vector<ll> cart;

	cin >> n_dorm >> n_cart;

	for (ll i = 0; i < n_dorm; ++i){
		cin >> aux;
		dorm.push_back(aux);
		
	}

	for (ll i = 0; i < n_cart; ++i){
		cin >> aux;
		cart.push_back(aux);
		
	}


	for (int i = 0; i < n_cart; ++i){

		while(!(cart[i] <= dorm[ind] + soma)){
			
			soma += dorm[ind];
			ind++;
			//cout << "here" << endl;
		}
		cout << ind+1 << ' ' << abs(dorm[ind] + soma - cart[i] - dorm[ind]) << endl;

	}
	


	return 0;
}