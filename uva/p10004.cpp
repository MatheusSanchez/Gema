//#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>


#define black -1;
#define white 1;


using namespace std;


vector<int> g[200];
int visit[200];
int colors[200];
int n_no,n_arestas,aux,aux2;

int bfs(){

	visit[0] = 0;
	queue <int> q;

	q.push(0);
	colors[0] = black;

	while(!q.empty()){

		int u = q.front();
		q.pop();
		int k = g[u].size();

		for (int i = 0; i < k; ++i){

			int v = g[u][i];

			if(visit[v] == -1){
				q.push(v);
				visit[v] = visit[u] + 1;
			}

			if(colors[v] == 0){
				colors[v] = colors[u]*(-1);
			}else{
				if(colors[v] == colors[u]){
					return 0;
				}
			}								
			
		}


	}

	return 1;

}

int main (){

	ios :: sync_with_stdio(false);

	while (1){


		cin >> n_no;

		if(n_no == 0){
			break;
		}

		cin >> n_arestas;

		for (int i = 0; i < n_arestas; ++i){
			cin >> aux >> aux2;
			g[aux].push_back(aux2);
			g[aux2].push_back(aux);
		}
		memset(visit,-1,sizeof visit);
		memset(colors,0,sizeof colors);

		/*for (int i = 0; i < n_arestas; ++i){
			cout << i << "-> ";
			for (int j = 0; j < g[i].size(); j++){
				cout << g[i][j] << " ";
			}
			cout << endl;
		}*/

	
		if(bfs() == 1){
			cout << "BICOLORABLE." << endl;
		}else {
			cout << "NOT BICOLORABLE." << endl;
		}

		for (int i = 0; i < n_no; ++i){
			g[i].clear();
		}


	}

	return 0;
}