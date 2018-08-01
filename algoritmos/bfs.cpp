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

void bfs(int no){

	fill(dist.begin(),dist.end(),false); // seta todos os nós para não visitados (O(n))

	dist[no] = 0; // visitamos o nó

	queue<int> q;	
	q.push(no);	// coloca o nó na fila

	while(!q.empty()){ // enquanto a fila não estiver vazia

		int u = q.front();  // nó da frente da fila
		q.pop();	// tiramos o nó

		for (int i = 0; i < g[u].size(); ++i){

			int v = g[u][i].first; // para cada aresta do nó atual

			if(dist[v] == false){ // se nao visitamos ele

				dist[v] = dist[u] + 1; // visita e ++ no vetor de distância;
				cout << v << " ";
				q.push(v);	

			}
		}

		cout  << endl;

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
		cout << "BFS para o nó " << i << endl;
		bfs(i);
	}

	return 0;
}