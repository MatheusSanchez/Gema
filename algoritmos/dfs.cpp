#include <bits/stdc++.h>
#define MAX 200
#define ll long long
#define true 1
#define false -1

using namespace std;


typedef pair<int ,int> p_i; // pair int
typedef vector<p_i> v_p_i; // vector pair int

typedef vector<int> vi; // vector int

vector<v_p_i> g(MAX); // vector de vector pair int; (lista de adjacencia) 
vi dist (MAX,false); // vector de distancias; // tamanho: MAX // val_inicial = false

int num_nos,num_arestas,A,B;

void dfs (int u){

	
	dist[u] = true; // vetor de distancia, que na verdade é um vetor de visitado

	printf("%d\n", u);

	for (int i = 0; i < g[u].size(); ++i){ // para todo vizinho do nó atual

		p_i v = g[u][i]; // nó atual

		if(dist[v.first] == false){ // se ele nao foi visitado ainda 
			dfs(v.first);	// chama dfs pra ele;
		}
	}

}

void print_graph(){
	for (int i = 0; i < num_nos; ++i){ // para cada nó
		cout << i << " -> ";
		for (int j = 0; j < g[i].size(); j++){ // para cada aresta do nó
			cout << g[i][j].first << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(){


	cin >> num_nos >> num_arestas; // le numero de nós e arestas

	for (int i = 0; i < num_arestas; ++i){

		cin >> A >> B;
		g[A].push_back(make_pair(B,0)); // grafo bidirecional
		g[B].push_back(make_pair(A,0)); // 0 é o peso de cada aresta

	}

	print_graph();

	for (int i = 0; i < num_nos; ++i){
		fill(dist.begin(),dist.end(),false); // seta todos os nós para não visitados (O(n))

		cout << "DFS para o nó " << i << endl;
		dfs(i);
	}

	return 0;
}