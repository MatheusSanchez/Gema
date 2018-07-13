#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main (){

	ios :: sync_with_stdio(false);
	map<string ,int> m;
	map<string, int> :: iterator it;

	int n;
	int maior = 0;
	string str;
	string aux;
	char c;

	cin >> n;

	cin >> c;
	aux += c;
	cin >> c;
	aux += c;

	n-=2;

	while(n>=0){
		//cout << aux << endl;
		m[aux]++;
		aux = aux[1];
		cin >> c;
		aux += c;
		n--;
	}	


	for (it = m.begin(); it != m.end(); it++){
		if(it->second > maior){
			maior = it->second;
			aux = it->first;
		}
	}

	cout << aux << endl;


	return 0;	
}