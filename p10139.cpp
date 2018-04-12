#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <iostream>
#include <bitset>
#include <stdio.h>

#define MAX 47000
				
#define ll long long
#define pb push_back

using namespace std;

int main (){
	bitset<MAX> v;
	v.set();
	v[0] = 0;
	v[1] = 0;
	v[2] = 1;
	int i = 2;

	vector<int> primos;
	primos.push_back(2);

	while(i*2 < MAX){ // crivo otmizado
		i = i*2;
		v[i] = 0;
	}

	for (i = 3; i < MAX; i+=2){
		
		if(v[i] == 1){
			primos.push_back(i);
			for (int j = i*2; j < MAX; j+=i){
				v[j] = 0;
			}

		}		
	}


	int fatorial,divisor;
	map<int,int> fatores;
	map<int,int> divisor_f;
	map<int,int> ::iterator it;
	map<int,int> ::iterator it2;
	
	while(cin >> fatorial >> divisor){	
		

		int numero = divisor;
		int indice_primos = 0;
		int aux = 0;	
		vector< pair<int,int> > v;
		vector< pair<int,int> >::iterator it;


		while(numero > 1){
			cout << numero << " " << primos[indice_primos] << endl;
			if(numero % primos[indice_primos] == 0){
				numero = numero / primos[indice_primos];
				aux++;
				//divisor_f[primos[indice_primos]]++;
			}else{
				if(aux != 0){
					cout << primos[indice_primos] << "->" << aux << endl;
					v.pb(make_pair(primos[indice_primos],aux));

				}
				aux = 0;
				indice_primos++;
			}

		}
		if(aux != 0){
			//cout << primos[indice_primos] << "->" << aux << endl;
			v.pb(make_pair(primos[indice_primos],aux));
		}


		for (it = v.begin(); it != v.end(); it++){
			cout << it->first << "->" << it->second << endl;	
		}

		if(divide(fatorial,divisor,v)){
			cout << divisor <<  " divide " << fatorial << "!" << endl;
		}else{
			cout << divisor <<  " does not divide " << fatorial << "!" << endl;
		}

		v.clear();
	}	
	return 0;
}
