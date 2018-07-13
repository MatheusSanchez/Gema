#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;

typedef vector<int> vi;
typedef long long ll;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> graph;


int main (){

	int n_e,s_t,a;

	cin >> n_e >> s_t;

	set<int> resp;

	vi aux;

	for (int i = 0; i < n_e; ++i){
		//it = NULL;
		cin >> a;
		
		if(resp.find(a) == resp.end()){
			resp.insert(a);
			aux.push_back(i);
		}
	}

	if(resp.size() >= s_t){
		cout << "YES" << endl;
		for (int i = 0; i < s_t; ++i){
			cout << aux[i] + 1 << " ";
		}
		cout << endl;
	}else{
		cout << "NO" << endl;	
	}

	

	


}