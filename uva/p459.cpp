#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pi;
typedef vector<pi> vpii;
typedef vector<vpii> graph;
typedef vector<int> vi;

graph g(26);

void p_graph(){
	for (int i = 0; i < g.size(); ++i){
		for (int j = 0; j < g[i].size(); j++){
			cout << g[i][j].second << " ";
		}
		cout << endl;
	}
}

	
int main (){

	int ncases,A,B;
	cin >> ncases;
	
	cout << ncases << endl;

	while(ncases){
		//getline();

		char b;
		scanf("%c",&b);
		//b -= 65;
		cout << "here" << endl;
		cout << b << endl;

		/*while(cin >> A >> B){
			A-=65;
			B-=65;
			cout << A << " "<< B;
			g[A].push_back(make_pair(0,B));
		}
		//p_graph();*/


		ncases--;
	}


	return 0;
}