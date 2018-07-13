#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;

typedef vector<int> vi;
typedef long long ll;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> graph;


int main (){

	int n_seq,aux,A;

	vector<vi> v(1000000);
	vi sum(1000000);
	cin >> n_seq;



	for (int i = 0; i < n_seq; ++i){
			cin >> aux;
			for (int j = 0; j < aux; j++){
				cin >> A;
				v[i].push_back(A);
				sum[i]+=A;
			}
	}	

	for (int i = 0; i < n_seq; ++i){
		
		cout << i << "-> ";
		for (int j = 0; j < v[i].size(); j++){
			cout << v[i][j] << " ";		
		}
		cout << "Sum " << sum[i];
		cout << endl;
	}	

	for (int i = 0; i < n_seq; ++i){
		for (int j = i+1; j < n_seq; j++){
			int dif = sum[i] - sum[j];
		}
	}



}