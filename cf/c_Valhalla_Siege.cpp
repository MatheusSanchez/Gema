#include <bits/stdc++.h>
#define ll long long
using namespace std;


vector<ll> w_s;
vector<ll>::iterator it;

int ini,fim,aux;

void b_s(ll key){
			
	int meio;

	while(fim >= ini){

		meio = (fim+ini)/2;

		if(w_s[meio]-aux > key){
			fim = meio -1;
		}else if(w_s[meio]-aux < key){
			ini = meio + 1;
		}else{
			break;
		}

	}

	aux += w_s[meio];
	ini = meio;	

	cout  << "Resp: " << w_s.size() - ini - 1 <<endl;
	cout  << "Ini: " << ini << " meio: " << meio << " Fim: " << fim << endl;
	cout  << "w_s[meio]: " << w_s[meio] << " Aux " << aux << endl;

	
}

int main(){

	ios :: sync_with_stdio(false);	

	ll n,q,aux;

	cin >> n >> q;

	vector<ll> w;
	
	vector<ll> f_p_m;

	cin >> aux;	
	w.push_back(aux);
	w_s.push_back(aux);

	for (ll i = 1; i < n; ++i){
		cin >> aux;
		w.push_back(aux);
		w_s.push_back(w_s[i-1] + aux);
	}

	for (ll i = 0; i < n; ++i){	
		cin >> aux;
		f_p_m.push_back(aux);
	}


	
	ini = 0;
	fim = n-1;
	aux = 0;

	cout << "Vetor soldados" << endl;
	for (int i = 0; i < n; ++i){	
		cout << w[i] <<  " ";
	}

	cout << endl;

	cout << "Vetor sum" << endl;

	for (int i = 0; i < n; ++i){	
		cout << w_s[i] <<  " ";
	}

	cout << endl;

	cout << "Vetor flechas" << endl;
	for (int i = 0; i < n; ++i){	
		cout << f_p_m[i] <<  " ";
	}


	cout << endl<< endl;

	for (ll i = 0; i < q; ++i){
		fim = w_s.size()-1;
		b_s(3);
		break;
	}	


	/*
	for (int i = 0; i < n; ++i){	
		cout << w[i] <<  " ";
	}

	cout << endl;

	for (int i = 0; i < n; ++i){	
		cout << w_s[i] <<  " ";
	}

	cout << endl;

	for (int i = 0; i < n; ++i){	
		cout << f_p_m[i] <<  " ";
	}
	*/
}	