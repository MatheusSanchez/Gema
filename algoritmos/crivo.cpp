// Crivo de Eratóstenes, pega todos os primos de 0 a MAX
#include <bits/stdc++.h>
#define MAX 1009
#define ll long long
#define true 1
#define false -1

using namespace std;

bitset<MAX+1> bs;
vector<int> primes;

void crivo (){

	bs.set(); // seta todos os valores para um

	bs[0] = 0;
	bs[1] = 0;

	ll i = 2; // primeiro primo 

	primes.push_back(2);

	while(i + 2 < bs.size()){	// tira todos os pares;
		i += 2;
		bs[i] = 0;
	}

	for (ll i = 3; i < sqrt(bs.size()); ++i){ // até a raiz
		if(bs[i]){ // se o numero é primo
			for (ll j = i*i; j < bs.size(); j+=i){ // vamos tirar todos seus múltiplos
				bs[j] = 0; 
			}
			primes.push_back(i); // e colocar ele na lista de primos
		}
	}

	for (ll i = sqrt(bs.size()); i < bs.size(); i++){ // colocando na lista os que sobraram
		if(bs[i]){
			primes.push_back(i);	
		}
	}

}



int main(){

	crivo();

	cout << "Primos de 0 a " << MAX << endl;
	for (int i = 0; i < primes.size(); ++i){
		cout << primes[i] << " ";	
	}

	cout << endl;


	return 0;
}