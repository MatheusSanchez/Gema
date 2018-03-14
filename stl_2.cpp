//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>

using namespace std;		


int main(){

	map<char,char> m;
	int tam;
	string linha;

	char v[] = {"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};

	tam = strlen(v);

	for (int i = 1; i < tam; i++){
			m[v[i]] = v[i-1];
	}	

	while(getline(cin,linha)){
		tam = linha.length();

		for (int i = 0; i < tam; ++i){	
			if(linha[i] == ' '){
				cout << ' ';
			}else{
				cout << m[linha[i]];	
			}

		}
		cout << '\n';
	}

}