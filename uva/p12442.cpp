#include <bits/stdc++.h>	
using namespace std;

typedef vector<int> vi;

int main(int argc, char const *argv[]){

	ios :: sync_with_stdio(false);

	int cases;
	cin >> cases;

	vi resp(cases,-1);

	for (int i = 0; i < cases; ++i){

		int n_marc;
		cin >> n_marc;

		vi g(n_marc);
		vi visit(n_marc,-1);
		vi dist(n_marc,0);
		
		int maior = 0;

		for (int k = 0; k < n_marc; ++k){

			int A,B;
			cin >> A >> B;
			A--,B--;
			g[A] = B;

		}

		for (int k = 0; k < n_marc; k++){

		//	cout << "k " << k << endl;
			int count = 1;
			int u = k;

			while(visit[u] != 1){
				//cout << "u " << u << endl;
				visit[u] = 1;
				u = g[u];
				count++;
			}		
			//cout << "sai " << k << endl;
			dist[k] = count + dist[u];	

			
			/*cout << endl;
			cout<< "dist " << endl;
			for (int z = 0; z < n_marc; ++z){
				cout << dist[z] << " ";
			}
			cout << endl;
			cout<< "visitados " << endl;
		
			for (int z = 0; z < n_marc; ++z){
				cout << visit[z] << " ";
			}
			cout << endl;	*/


			if(dist[k] > maior){
				resp[i] = k+1;
				maior = dist[k];
			}
			if(u == k && count > 1){
				u = g[u];
				int ultimo = u;
				while(u != k){
					dist[u] = dist[k];
					ultimo = u;
					u = g[u];
				}
				k = ultimo;
			}	
			//fill(visit.begin(),visit.end(),-1);
		}


	}
	for (int i = 0; i < cases; ++i){
		cout << "Case "<< i+1 << ": " << resp[i] << endl;
	}

	
	return 0;
}