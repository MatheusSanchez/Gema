#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,m;
vector< pair<ll,ll> > v(101);

int c(ll c){
	int ans = 0;
	while(c%3 == 0){
		c = c/3;
		ans++;
	}

	return -ans;

}


int main (){

	scanf("%lld",&n);	
	v.resize(n);	

	for (int i = 0; i < n; ++i){
		scanf("%lld",&v[i].second);
		v[i].first = c(v[i].second);
	}

	sort(v.begin(),v.end());

	for (int i = 0; i < n; ++i){
		printf("%lld ", v[i].second);	
	}	
	printf("\n");


	return 0;	
}