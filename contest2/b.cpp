#include <bits/stdc++.h>

using namespace std;

int main(){

	ios :: sync_with_stdio(false);

	int n,count = 0;
	cin >> n;

	string std;
	string aux;

	cin >> std;

	for (int i = 0; i < n - 2; ++i){
		aux = std.substr (i,3); 
		if(aux.compare("xxx") == 0){
			count++;
		}
		//cout << aux << endl ;
	}
	
	cout << count<< endl;

	return 0;
}