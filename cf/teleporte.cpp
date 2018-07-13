#include <bits/stdc++.h>

using namespace std;

vector<int> g[100];
int nos;

/*void bfs(int vertice){

	int dist[100];
	memset(dist, -1, sizeof dist);
	dist[vertice] = 0;

	queue <int> q;

	q.push(vertice);

	while(!q.empty()){
		int u = q.front();
		q.pop();
		cout << u << " -> ";

		for (int i = 0; i < g[u].size(); ++i){
			int v = g[u][i];
			if(dist[v] == -1){
				q.push(v);
				dist[v] = dist[u] + 1;
				cout << v << " ";
			}
		}

		cout << endl;
	}

	cout << "Vet dist" << endl;
	for (int i = 0; i < nos; ++i){
		cout << dist[i] << " ";
	}
	cout << endl;

}*/

int dist[100];

void dfs(int vertice, int d){

	

	dist[vertice] = d;


	for (int i = 0; i < g[vertice].size(); ++i){
		int u = g[vertice][i];

		if(dist[u] == -1){
			cout << u << " ";
			dfs(u,d+1);
			cout << endl;
		}	
	}

	


}



int main (){

	ios::sync_with_stdio(false);	

	int arestas,ini,dest;
	cin >> nos >> arestas >> ini >> dest;
	ini--;dest--;

	int aux,aux2;

	

	for (int i = 0; i < arestas; ++i){
		cin >> aux >> aux2;
		aux--;aux2--;
		g[aux].push_back(aux2);
		//g[aux2].push_back(aux);
	}

	for (int i = 0; i < nos; ++i){
		cout << i << "-> ";
		for (int j = 0; j < g[i].size(); ++j){
			cout << g[i][j] << ' ';
		}
		cout << endl;
	}



	/*cout << "BFS" << endl;
	
	for(int i = 0; i < nos; i++){
		bfs(i);
	}*/

	cout << "DFS" << endl;
	
	for(int i = 0; i < nos; i++){
		memset(dist, -1, sizeof dist);
		cout << "no " << i << endl;
		dfs(i,0);
		cout << "Vetor de distancia" << endl;

		for (int i = 0; i < nos; ++i){
			cout << dist[i] << " ";
		}
		cout << endl;
	}


}