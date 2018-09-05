#include <bits/stdc++.h>
#define MAX 1000001
#define true 1
#define false -1
#define inf 0x3f3f3f3f // numero grandão

#define ll long long

using namespace std;

typedef vector<int> vi; // vector int

typedef pair<int ,int> p_i; // pair int
typedef vector<p_i> v_p_i; // vector pair int
typedef vector<v_p_i> graph; // vector de vector pair int; (lista de adjacencia) 

bitset<1000001> bs;


void crivo (){

	
	bs.set();
	bs[0] = bs[1] = 0;


	for (ll i = 2; i*i < MAX; i++){
		if(bs[i]){
			
			for (ll j = i*i; j < MAX; j+=i){
				bs[j] = 0;
			}
		}
	}


}


int main (){

	ios :: sync_with_stdio(false);
	crivo();
	ll n,p;
	cin >> n;

	while(n--){
		cin >> p;
		
		//cout << sqrt(1000000000000) << endl;
		if(sqrt(p) == (int)sqrt(p) && p!=1 && bs[sqrt(p)]){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}


}