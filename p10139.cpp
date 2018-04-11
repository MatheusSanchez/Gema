#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <iostream>
#include <bitset>
#include <stdio.h>

#define MAX 10000000
#define ll long long

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


	/*for (int i = 0; i < primos.size(); ++i){
		cout << primos[i] << " ";
	}*/

	int fatorial,divisor;
	map<int,int> fatores;
	map<int,int> divisor_f;
	map<int,int> ::iterator it;
	map<int,int> ::iterator it2;
	
	while(cin >> fatorial >> divisor){	
		
		//getchar();
		
		
		//exit(0);
		

			int numero = divisor;
			int indice_primos = 0;
		
		while(numero > 1){
			cout << numero << " " << primos[indice_primos] << endl;
			if(numero % primos[indice_primos] == 0){
				numero = numero / primos[indice_primos];

				divisor_f[primos[indice_primos]]++;

			}else{
				indice_primos++;
			}

		}


		
		

		vector<ll> num_fatorial;

		for (int i = 0; i <= fatorial; ++i){
			num_fatorial.push_back(i);
		}
	
		for (it2 = divisor_f.begin(); it2 != divisor_f.end(); it2++){

			int aux = it2->first;

			//cout << it2->first << " " << it2->second << " -> " << aux << endl;
			while( aux <= fatorial && it2->second != 0){
				if(num_fatorial[aux] > 1 && num_fatorial[aux] % it2->first == 0){
					//cout << it2->first << "  " << it2->second << endl;
					num_fatorial[aux] /= it2->first;
					it2->second--;
					/*for (int i = 0; i <= fatorial; ++i){
						cout << num_fatorial[i] << " ";
					}*/
					//cout << endl;
				}else{
					aux += it2->first;
				}
				//cout << "Chama";
			}
			

		}


		it2 = divisor_f.begin();
		for (; it2 != divisor_f.end(); it2++){
			if(it2->second != 0){
				//cout << it2->first << "-> " << it2->second << endl;
				cout << divisor << " does not divide " << fatorial << "!" << endl;	
				break;
			}
		}
		if(it2 == divisor_f.end()){
			cout << divisor << " divide " << fatorial << "!" << endl;	
		}
	

		divisor_f.clear();
		num_fatorial.clear();

	}


	return 0;
}