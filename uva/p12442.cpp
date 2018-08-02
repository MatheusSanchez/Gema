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
		int maior = -1;

		for (int k = 0; k < n_marc; ++k){

			int A,B;
			cin >> A >> B;
			A--,B--;
			g[A] = B;

		}
		int flow = 0;

		for (int k = 0; k < n_marc; k++){

			int count = 1;
			int u = k;
			visit[u] = 1;
			u = g[u];

			while(visit[u] != 1){
			
				visit[u] = 1;
				u = g[u];
				count++;
			}
			
			if(count > maior){
				resp[i] = k+1;
				maior = count;
			}	
			fill(visit.begin(),visit.end(),-1);
		}


	}
	for (int i = 0; i < cases; ++i){
		cout << "Case "<< i+1 << ": " << resp[i] << endl;

	}

	
	return 0;
}