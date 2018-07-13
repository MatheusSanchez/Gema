
#include <bits/stdc++.h>
#define MAX 10000 // MAX CONJUNTOS
#define true 1
#define false 0

using namespace std;

int pai[MAX]; 
int dist[MAX]; 

int find(int n){ // acha o pai de um nó qualquer

	if(pai[n] == n){ // se ele nao for o pai de ele mesmo
		return n;
	}else{
		return (pai[n] = find(pai[n])); // chamamos recursivamente para seu pai e atualizamos para diminuir
	}									// a altura da arvore
}

void join (int x,int y){

	x = find(x); // vamos juntar o nó raiz
	y = find(y);

	if(x == y)
		return;
	
	if(dist[x] > dist[y]){ // nao queremos aumentar a altura entao, colocaremos o menor no maior;
		pai[x] = y;
	}else if(dist[y] > dist[x]){
		pai[y] = x;

	}else{ // caso as distancias sejam iguais precisamos escolher algum e icrementar no vetor de dist

		pai[y] = x;
		dist[x]++;
	}
	
}
void print_pai(){

	cout << "PAI " << endl;

	for (int i = 0; i < 10; ++i){
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; ++i){
		cout << pai[i] << " ";
	}
	cout << endl;

}

void print_dist(){

	cout << "DIST " << endl;

	for (int i = 0; i < 10; ++i){
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; ++i){
		cout << dist[i] << " ";
	}
	cout << endl;
	
}



int main(){
		
	// F para fusao
	// C consulta (retorna true se dois nós estao no mesmo conjunto)

	int no1,no2;

	for (int i = 0; i < MAX; ++i){
		pai[i] = i;
	}


	char op;
	
	cin >> op;

	while(op != 'P'){

		if(op == 'C'){
			cin >> no1;
			cout << "PAI de " << no1 << " = " << find(no1) << endl;
			
		}else{
			cin >> no1;
			cin >> no2;
			join(no1,no2);
			
		}

		print_pai();
		print_dist();
		cout << endl;

		cin >> op;
	}
	


	return 0;
}