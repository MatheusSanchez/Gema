#include <bits/stdc++.h>

using namespace std;
vector<int> v;


void bb(int key){

	int ini,fim,meio;

	ini = 0;
	fim = v.size() -1;

	while(fim >= ini){

		meio = (fim+ini)/2;

		if(v[meio] > key){
			fim = meio -1;
		}else if(v[meio] < key){
			ini = meio + 1;
		}else{
			break;
		}

	}


	cout  << "Ini: " << ini << " meio: " << meio << " Fim: " << fim << endl;
	cout  << "v[meio]: " << v[meio] << endl;
}

int main (){

	for (int i = 1; i < 20; i*=2){
		v.push_back(i);
	}


	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;

	int aux;
	//cout << "Meus deudsuda" << endl;
	cin >> aux;

	bb(aux);


}