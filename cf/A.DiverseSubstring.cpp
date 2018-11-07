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
	

int main (){

	ios :: sync_with_stdio(false);

	int n;
	cin >> n;

	string in;
	cin >> in;

	//cout << in << endl;

	for (int i = 1; i <= (n/2); ++i){
		int tam = i*2;

		for (int j = 0; j < n-tam+1; ++j){
			string sub = in.substr(j,tam);

			//cout << sub << endl;
			map<char,int> count;
			map<char,int> :: iterator it;

			for (int k = 0; k < sub.size(); k++){
				count[sub[k]]++;
			}
			int valeu = 0;
			
			
			for (it = count.begin(); it != count.end(); it++){
				//cout << it->first << endl;
				//cout << "aqui" << endl;
				if(it->second > i){
					valeu = 1;
					break;
				}

			}

			if(valeu == 0){
				
				cout << "YES" << endl << sub << endl;	
				exit(0);
			}

		}

	}

	cout << "NO" << endl;	
}