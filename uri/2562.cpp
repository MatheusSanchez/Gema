#include <bits/stdc++.h>
#define MAX 1001
#define ll long long
#define true 1
#define false -1

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;


vector<int> visit(MAX);

int n_especies,info,A,B;

void bfs(int no,vector<vpi> g){

	fill(visit.begin(),visit.end(),false);

	queue <int>q;
	q.push(no);
	visit[no] = true;

	while(!q.empty()){

		int v = q.front();
		q.pop();
		
		for (int i = 0; i < g[v].size(); ++i){
			
			int u = g[v][i].first;

			if(visit[u] == false){
				visit[u] = true;
				
				q.push(u);
			}	
		}
	}	

}

int main(){

	ios :: sync_with_stdio(false);

	while(cin >> n_especies >> info){
		vector<vpi> g(MAX);

		//printf("%d %d\n", n_especies,info);

		for (int i = 0; i < info; ++i){

			cin >> A >> B;
			g[A].push_back(make_pair(B,0));
			g[B].push_back(make_pair(A,0));	

		}

		cin >> A;
		bfs(A,g);
		B = 0;

		for (int i = 1; i <= n_especies;i++){
			if(visit[i] == true){	
				B++;
			}
		}

		cout << B << endl;

	}
	return 0;
}