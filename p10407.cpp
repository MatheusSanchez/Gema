//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;


void processa(vector<int> v){
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}


int main(){

	int aux;
	vector<int> v;

	while(cin >> aux){
		if(aux == 0){
			if(!v.empty()){
					processa(v);
					v.clear();
			}
		
		}else{
			v.push_back(aux);
		}
	}




}