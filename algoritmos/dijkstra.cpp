#include <bits/stdc++.h>
#define max 100
#define inf 0x3f3f3f3f
		
using namespace std;

int n_nos,n_arestas,A,B,peso;

typedef pair<int,int> pii;   // nó da outra ponta, peso
typedef vector<pii> vpii; 
typedef vector<vpii> graph;

typedef vector<int> vi;

graph adjList(max);

void dijkstra(int no){

	int dist[n_nos]; // vetor de distância
	int pred[n_nos]; // vetor de predecessores

	for (int i = 0; i < n_nos; ++i) // todo nó tem distancia infinita para o outro
		dist[i] = inf;
	

	dist[no] = 0; // nó de partida pra ele mesmo distancia = 0
	pred[no] = -1; // predecessor do nó partida nao existe


	priority_queue <pair <int,int> >pq;


	pq.push(make_pair(0,no)); // colocando na fila o primeiro nó

	while(!pq.empty()){
		int u = pq.top().second // pegando o nó atual;
		pq.pop(); 

		for (int i = 0; i < adjList[u].size(); i++){
			int v = g[u][i].first; // nó vizinho
			int w = g[u][i].second;	// peso da aresta que liga u a v

			if(dist[v] > dist[u] + w){ // se a distancia ja medida for maior, vamos trocar a aresta
				dist[v] =  dist[u] + w;
				prede[v] = u;
				pq.push(make_pair(-dist[v],v)); // jogamos na fila de prioridade,
				// sinal invertido pois queremos sempre as menores arestas;	
			}

		}
	}


}


void print_graph(){

	for (int i = 0; i < n_nos; ++i){
			cout << i << "-> ";
			for (int j = 0; j < adjList[i].size(); j++){
				cout << adjList[i][j].first << " ";
			}
			cout << endl;
	}

}


int main (){

	

	cin >> n_nos >> n_arestas;

	for (int i = 0; i < n_arestas; ++i){ 
			cin >> A >> B >> peso;

			adjList[A].push_back(make_pair(B,peso));
	}


	print_graph();


}