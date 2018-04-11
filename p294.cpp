#include <bits/stdc++.h>
#include <bitset>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <math.h>

#define ll long long

#define max 1000


using namespace std;


typedef struct ${
	int qnt_d;
	ll ind;	
}maior;


int main (){

	int k;
	vector<int> primos;
	ll l,u;

	bitset<max> v;
	v.set();
		v[0] = 0;
		v[1] = 0;
		v[2] = 1;	

		primos.push_back(2);

	for (int i = 4; i < max; i+=2){
			v[i] = 0;
	}

		for (int i = 3; i < max; i+=2){
			if(v[i] == 1){

				primos.push_back(i);
				
				int j = i + i;
				while(j < max){
					v[j] = 0;
					j+=i;
				}

			}
		}

	for (int i = 0; i < primos.size(); ++i){
			cout << primos[i] << " ";
	}
	


	cin >> k;

	while(k != 0){

		cin >> l >> u;
		
		maior resp;
		resp.ind = 0;
		resp.qnt_d = 0;

			

		int aux = 0;

		ll numero;
		int indice_primos = 0;

		

		for (ll i = l; i <=  u; ++i){
			aux = 0;
			numero = i;
			indice_primos = 0;

			while(numero > 1){
				
					
				if(numero % primos[indice_primos] == 0){
					cout << numero << "-" <<  primos[indice_primos] << endl;
					numero = numero / primos[indice_primos];
					if(!(numero == primos[indice_primos])){
						aux++;
					}else{
						break;
					}
					
				}else{
					indice_primos++;
				}
			}

			if(aux > resp.qnt_d){
				resp.qnt_d = aux;
				resp.ind = i;
			}
			

		}


		
		resp.qnt_d+=2;
		cout << "Between "<< l << " and " << u << ", " << resp.ind 
		<< " has a maximum of "<< resp.qnt_d << " divisors." << endl;


		k--;
	}

}