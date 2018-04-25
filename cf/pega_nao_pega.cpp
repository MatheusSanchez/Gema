#include <bits/stdc++.h>

using namespace std;


int bt(int soma_atual, int soma_dese, vector<int> v, int cout, int pos){
	/*if(soma_atual > soma_dese){
		return 0;
	}if(soma_atual == soma_dese){
		return 1;
	}else{
		int aux = v.size();
		for (; pos < aux; pos++){
			soma_atual += v[pos];
			if(bt(soma_atual,soma_dese,v,cout,pos+1) == 1){
				soma_atual -= v[pos];
				cout++;
			}else{
				break;
			}
		}
	}*/


}

int main (){

	int k,soma;
	vector<int> v;
	int aux;

	cin >> k;
	cin >> soma;

	while(k>0){
		cin >> aux;
		v.push_back(aux);
		k--;
	}


	for (int i = 0; i < v.size(); ++i){
		cout << v[i] << " ";
	}



	cout << endl;

}