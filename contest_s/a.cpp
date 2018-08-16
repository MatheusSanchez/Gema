#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;

typedef vector<int> vi;
typedef long long ll;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> graph;


int main (){

	int n,aux=0,a,count=0;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; ++i){
		cin >> a;
		if(a > aux){
			aux = a;
		}else{
			count++;
			v.push_back(aux);
			aux = a;
		}
	}

	count++;
	v.push_back(aux);
	aux = a;

	cout << count << endl;
	for (int i = 0; i < v.size(); ++i){
		cout << v[i] << " ";
	}


}