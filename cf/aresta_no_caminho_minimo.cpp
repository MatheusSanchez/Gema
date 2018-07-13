#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define MAX 100001
using namespace std;

typedef pair <int,int> pii;
typedef vector <pii> vpii;
typedef vector<vpii> graph;

typedef vector<int> vi;

int n_nos,n_arestas,origem,destino,A,B,peso;
graph g(MAX);

int prede[MAX];
int dist[MAX];

void print_prede(){

	//cout << endl;
	for (int i = 1; i <= n_nos; ++i){
		cout << i << '(' <<prede[i] << ") "; 

	}
	cout << endl;
}

void print_dist(){

	cout << "DIST" <<endl;
	for (int i = 1; i <= n_nos; ++i){
		cout << i << '(' <<dist[i] << ") "; 

	}
	cout << endl;

}

void dijkstra(int no){
	
	for (int i = 1; i <= n_nos; ++i){
		dist[i] = inf;
	}
	
	for (int i = 1; i <= n_nos; ++i){
		prede[i] = -1;
	}

	priority_queue <pair <int,int> >pq;
	dist[no] = 0;
	prede[no] = -1;

	pq.push(make_pair(0,no));

	while(!pq.empty()){

		int u = pq.top().second;
		pq.pop();
		cout << "NO " << u << endl;
		for (int i = 0; i < g[u].size(); ++i){
			int v = g[u][i].first;
			int w = g[u][i].second;
			cout << "V " << v <<" U " << u << endl;
			if(dist[v] >= dist[u] + w){
				dist[v] = dist[u] + w;	
				prede[v] = u;
				print_prede();
				print_dist();
				pq.push(make_pair(-dist[v],v));
			}
			cout << endl;
		}

	}


}


void print_graph(){
	for (int i = 0; i < n_arestas; ++i){
		cout << i << "-> ";
		for (int j = 0; j < g[i].size(); j++){
			cout << g[i][j].first << " ";
		}
		cout << endl;
	}
}

int main (){

	cin >> n_nos >> n_arestas >> origem >> destino;
	vpii resp;

	for (int i = 0; i < n_arestas; ++i){
		cin >> A >> B >> peso;
		//A--;B--;
		g[A].push_back(make_pair(B,peso));
		g[B].push_back(make_pair(A,peso));

		resp.push_back(make_pair(A,B));
	}	

	//origem--;
	//destino--;
	print_graph();
	dijkstra(origem);

	int k = prede[destino];

	while(){

	}	

	for (int i = 0; i < n_arestas; ++i){
		if(prede[resp[i].first] == resp[i].second || prede[resp[i].second] == resp[i].first ){
			cout << "sim" << endl;
		}else{
			cout << "nao" << endl;
		}
	}

	return 0;
}