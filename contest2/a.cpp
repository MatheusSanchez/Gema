#include <bits/stdc++.h>

using namespace std;

int main(){

	ios :: sync_with_stdio(false);

	int n,aux;	
	vector<int> v;
	vector<int> count(1001);
	vector<int> resp;

	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> aux;
		v.push_back(aux);
		count[aux]++;
	}

	for (int i = 0; i < n; ++i){
		if(count[v[i]] == 1){
			resp.push_back(v[i]);
			
		}else{
			count[v[i]]--;	
		}
	}
	cout << resp.size() << endl;

	for (int i = 0; i < resp.size(); ++i){
		cout << resp[i] << " ";
		/* code */
	}

	cout << endl;


	return 0;
}