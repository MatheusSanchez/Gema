#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main (){

	ios :: sync_with_stdio(false);
	
	ll n,num,aux;
	vector<ll> v;

	cin >> n >> num;	

	for (int i = 0; i < n; ++i){
			cin >> aux;
			v.push_back(aux);
	}	
	sort(v.begin(),v.end());
	

	

	if(num == 0){
		if(v[0] == 1){
			cout << -1 << endl;
		}else{
			cout << --v[0] << endl;
		}
		
		return 0;
	}else if(num == n){
		cout << v[num-1] << endl;
		return 0;
	}else{
		num--;

		if(v[num+1] > v[num]){
			cout << v[num] << endl;	
		}else{
			cout << -1 << endl;
		}

	}




	return 0;	
}