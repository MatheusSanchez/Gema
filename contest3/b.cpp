#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;

typedef vector<int> vi;
typedef long long ll;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> graph;

bool menor(const string& p1, const string& p2)
{
   return p1.size() < p2.size(); 
}


int main (){

	int a;
	vector<string> v;
	string aux;

	cin >> a;

	for (int i = 0; i < a; ++i){
		cin >> aux;
		v.push_back(aux);
	}

	sort(v.begin(),v.end(), menor);

	

	for (int i = a-1; i > 0; i--){

		if (v[i].find(v[i-1]) != std::string::npos) {
   		 	continue;
		}else{
			cout << "NO" << endl;
			return 0;
		}
		
	}

	cout << "YES" << endl;
	for (int i = 0; i < a; ++i){
		cout << v[i] << endl;	
	}


}