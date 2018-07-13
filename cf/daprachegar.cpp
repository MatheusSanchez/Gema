#include <bits/stdc++.h>


using namespace std;


int main (){

	vector<int> g[100000];

	int nos,arestas,ini,dest,aux,aux2;

	cin >> nos >> arestas >> ini >> dest;
	ini--;
	dest--;

	for (int i = 0; i < arestas; ++i){
		cin >> aux >> aux2;
		aux--;
		aux2--;
		g[aux].push_back(aux2);
	}

	/*
	for (int i = 0; i < nos; ++i){
		cout << i << " -> ";
		for (int j = 0; j < g[i].size(); ++j){
			cout << g[i][j] << " " ;
		}
		cout << endl;
	}*/

	int dist[nos];
	memset(dist, -1, sizeof dist); // setando distancia para -1

	queue<int> q;

    dist[ini] = 0; // distancia
    q.push(ini);	// vertice inicial na fila

    while(q.size()) {
        int u = q.front(); // primeiro da fila
        q.pop();
        
        for(int i = 0; i < g[u].size(); ++i) {
        	int v = g[u][i];
        	if(dist[v] == -1) {
                dist[v] = dist[u] + 1; //atualiza a distancia do vertice v
                q.push(v);
            }


        }
    }


    if(dist[dest] == -1){
    	 cout << "NAO" << endl;
    	return 0;
    }

   	 cout << "SIM" << endl;	


    
    return 0;

}