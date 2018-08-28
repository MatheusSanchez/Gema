// Crivo de Eratóstenes, pega todos os primos de 0 a MAX
// Fatoração de numeros em primos;
#include <bits/stdc++.h>
#define MAX 1009
#define ll long long
#define true 1
#define false -1

using namespace std;

bitset<MAX+1> bs;
vector<int> primos;

void crivo (){

	bs.set(); // seta todos os valores para um

	bs[0] = 0;
	bs[1] = 0;

	ll i = 2; // primeiro primo 

	primos.push_back(2);

	while(i + 2 < bs.size()){	// tira todos os pares;
		i += 2;
		bs[i] = 0;
	}

	for (ll i = 3; i < sqrt(bs.size()); ++i){ // até a raiz
		if(bs[i]){ // se o numero é primo
			for (ll j = i*i; j < bs.size(); j+=i){ // vamos tirar todos seus múltiplos
				bs[j] = 0; 
			}
			primos.push_back(i); // e colocar ele na lista de primos
		}
	}

	for (ll i = sqrt(bs.size()); i < bs.size(); i++){ // colocando na lista os que sobraram
		if(bs[i]){
			primos.push_back(i);	
		}
	}

}

vector<int> primeFactor (ll N){ // fatora o numero(N) em primos

	vector<int> fatores; // resultado

	ll i_primos = 0, fator = primos[i_primos]; // vamos interar por todos os primos gerados pelo crivo

	while(N != 1 && (fator * fator <= N)){ 

		while(N%fator == 0){ // enquanto n for divisivel pelo fator atual (primo)
			N = N/fator; // divide e coloca no vetor
			fatores.push_back(fator);
		}
		fator = primos[++i_primos]; // vai para o próximo primo

	}

	if(N != 1){ // se n for primo
		fatores.push_back(N);
	}


	return fatores;

}

map<ll,ll> primeFactorMap(ll N){ // fatora o numero(N) em primos

	map<ll,ll> fatores; // resultado

	ll i_primos = 0, fator = primos[i_primos]; // vamos interar por todos os primos gerados pelo crivo

	while(N != 1 && (fator * fator <= N)){ 

		while(N%fator == 0){ // enquanto n for divisivel pelo fator atual (primo)
			N = N/fator; // divide e coloca no vetor
			fatores[fator]++;
			
		}
		fator = primos[++i_primos]; // vai para o próximo primo

	}

	if(N != 1){ // se n for primo
		fatores[N]++;
	}


	return fatores;

}



int main(){

	crivo();
	int num;
	
	num = 15552;

	map<ll,ll> fatores = primeFactorMap(num);
	cout << num << " fatorado é ";


	for (map<ll,ll>::iterator it = fatores.begin(); it != fatores.end(); it++){
		cout << it->first << "^" << it->second << " ";	
	}

	/*vector<int> fatores = primeFactor(num);
	cout << num << " fatorado é ";


	for (int i = 0; i < fatores.size(); ++i){
		cout << fatores[i] << " ";
	}*/


	/*cout << "Primos de 0 a " << MAX << endl;
	for (int i = 0; i < primos.size(); ++i){
		cout << primos[i] << " ";	
	}*/



	cout << endl;


	return 0;
}