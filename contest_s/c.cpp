#include <bits/stdc++.h>
#include <math.h>
#define inf 0x3f3f3f3f

using namespace std;

typedef vector<int> vi;
typedef long long ll;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> graph;

int main (){

	int n,count = 0;
	cin >> n;

	vi v(n);
	map<int,int>m;

	for (int i = 0; i < n; ++i){
		cin >> v[i];
		
		m[v[i]]++;
	}

	for (int i = 0; i < n; i++){
		ll aux = 1;
		int va = -1;
		
		for (int j = 0; j < 32; j++){
			//cout << aux << endl;
			if( m[aux - v[i]] > 0) {
				if(v[i] != aux - v[i] || m[aux - v[i]] > 1) { 
					va = 1;
					break;
				}
			}

			aux = aux << 1;
		}

		if(va == -1){
			//cout << i << endl;
			count++;
		}
	}

	cout << count << endl;

}	