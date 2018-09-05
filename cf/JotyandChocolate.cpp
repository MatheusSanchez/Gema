// template fera
#include <bits/stdc++.h>

#define true 1
#define false -1
#define inf 0x3f3f3f3f // numero grandão

#define ll long long

using namespace std;

typedef vector<int> vi; // vector int

typedef pair<int ,int> p_i; // pair int
typedef vector<p_i> v_p_i; // vector pair int
typedef vector<v_p_i> graph; // vector de vector pair int; (lista de adjacencia) 


ll gcd(ll a, ll b) { return !a ? b : gcd(b % a, a); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main (){

	ios :: sync_with_stdio(false);

	ll cr = 0;
	ll cb = 0;
	ll n,d1,d2,p1,p2;

	cin >> n >> d1 >> d2 >> p1 >> p2;

	if(d2 < d1){
		ll aux = d1;
		d1 = d2;
		d2 = aux;

		aux = p1;
		p1 = p2;
		p2 = aux;
	}


	cr = n/d1;
	cb = n/d2;

	ll m = lcm(d1,d2);
	ll cm = n/m;

	if(p1 > p2){
		cout << cr*p1 + ((cb-cm)*p2) << endl;
	}else{
		cout << ((cr-cm)*p1) + (cb*p2) << endl;
	}

}