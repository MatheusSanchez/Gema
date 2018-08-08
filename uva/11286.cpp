#include <bits/stdc++.h>

using namespace std;

int main (){

	ios::sync_with_stdio(false);


	int qnt;

	cin >> qnt;

	while(qnt != 0){
		int maior=0,aux;
		map< set<int>,int > m;

		for (int i = 0; i < qnt; ++i){
			set<int> s;

			for (int i = 0; i < 5; ++i){
				cin >> aux;
				s.insert(aux);
			}
			
			aux = ++m[s];

			if(aux > maior){
				maior = aux;
			}
		}

		int resp = 0;
		for (map<set<int>,int>::iterator it=m.begin(); it!=m.end(); ++it){
    		if(it->second == maior){
    			resp+=maior;
    		}
   		}

   		cout << resp << endl;
		cin >> qnt;
	}


	return 0;
}