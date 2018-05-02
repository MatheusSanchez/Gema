#include <bits/stdc++.h>

using namespace std;



int c = 0;

void bt(int soma_atual, int soma_dese, vector<int> v, int ind){

	//cout << "S " << soma_atual << endl;

	if(soma_atual == soma_dese){
		c++;
		//cout << "Retorno c++" << endl;	
	
	}
		//cout << "For ind " << ind << endl;
		for (int i = ind; i < v.size(); i++){	
				//if(soma_atual <= soma_dese){
					//cout << "Mandando " << soma_atual << " i " << i << endl;
			bt(soma_atual+v[i],soma_dese,v,i+1);	
					//cout << "return " << soma_atual << " i " << i << endl;
				//}
		}
	
	
		
}

int main (){

	ios :: sync_with_stdio(false);

	int k,soma;
	vector<int> v;
	int aux;

	cin >> k;
	cin >> soma;

	while(k>0){
		cin >> aux;
		v.push_back(aux);
		k--;
	}


	

	
	//sort(v.begin(),v.end());
	
	/*for (int i = 0; i < v.size(); ++i){
		cout << v[i] << " ";
	}
	cout << endl;*/

	//bt(v[0],soma,v,0+1);

	for (int i = 0; i <= v.size(); ++i){
			
		bt(v[i],soma,v,i+1);
	}
	cout << c;




	cout << endl;

}