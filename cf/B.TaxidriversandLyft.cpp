// template fera
#include <bits/stdc++.h>

#define true 1
#define false -1
#define inf 0x3f3f3f3f // numero grandão

#define ll long long

using namespace std;

typedef vector<int> vi; // vector int

typedef pair<int ,int> p_i; // pair int
typedef vector<p_i> v_p_i; // vector pair int
typedef vector<v_p_i> graph; // vector de vector pair int; (lista de adjacencia) 


int main (){

	ios :: sync_with_stdio(false);

	int x,nr,nt;

	cin >> nr;
	cin >> nt;

	vi vet(nr+nt);
	vi vett;
	vi vetr;

	for (int i = 0; i < nr+nt; ++i){
		cin >> vet[i];
	}

	for (int i = 0; i < nr+nt; ++i){
		cin >> x;
		if(x == 1){
			vett.push_back(vet[i]);
		}else{
			vetr.push_back(vet[i]);	
		}
	}
/*
	cout << "Vet T" << endl;
	for (int i = 0; i < vett.size(); ++i){
		cout << vett[i] << " ";	
	}
	cout << endl;


	cout << "Vet R" << endl;
	for (int i = 0; i <  vetr.size(); ++i){
		cout << vetr[i] << " ";	
	}

*/	
	vi resp(nt);

	for (int i = 0; i < vetr.size(); ++i){
		ll dist = inf;
		int ind; 
		for (int j = 0; j <  vett.size(); j++){
			if(abs(vetr[i]-vett[j]) < dist ){
				dist = abs(vetr[i]-vett[j]);
				
				ind = j;
			}
		}	
		resp[ind]++;
	}

	for (int i = 0; i < resp.size(); ++i){
		cout << resp[i] << " ";
	}

	cout << endl;

}