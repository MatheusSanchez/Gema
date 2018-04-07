//#include <bits/stdc++.h>

#include <stdio.h>
#include <queue>
#include <iostream>
#define tam_visitado 10

	
typedef struct ${
	int digitos[4];
	int pro;	
}state;

using namespace std;

int moves[8][4] = { {1,0,0,0},
					{-1,0,0,0},
					{0,1,0,0},
					{0,-1,0,0},
					{0,0,1,0},
					{0,0,-1,0},
					{0,0,0,1},
					{0,0,0,-1}};


void todos_p(state atual ,state *p){

	

	for (int i = 0; i < 8; ++i){

		p[i].digitos[0] = atual.digitos[0] + moves[i][0];
		p[i].digitos[1] = atual.digitos[1] + moves[i][1];
		p[i].digitos[2] = atual.digitos[2] + moves[i][2];
		p[i].digitos[3] = atual.digitos[3] + moves[i][3];
		p[i].pro = atual.pro + 1;
		for (int j = 0; j < 3; j++){
			if(p[i].digitos[j] > 9){
				p[i].digitos[j] = 0;
			}


			if(p[i].digitos[j] < 0){
				p[i].digitos[j] = 9;
			}
		}
		
	}


}

int compara(state inicial,state final){

	for (int i = 0; i < 4; ++i){
		if(inicial.digitos[i] != final.digitos[i] ){	
			return -1;
		}
	}

	//printf("retornando 1\n");
	return 1;

}

int bt(state inicial,state final,int visitados[10][10][10][10]){

	state next[8];
	todos_p(inicial,next);
	queue <state>p;

	/*printf("inicial\n");
	printf("%d %d %d %d\n",inicial.digitos[0],inicial.digitos[1],inicial.digitos[2],inicial.digitos[3]);
	printf("------------\n");

	for (int i = 0; i < 8; ++i){
		printf("%d %d %d %d\n",next[i].digitos[0],next[i].digitos[1],next[i].digitos[2],next[i].digitos[3]);
	}*/

	if(visitados[inicial.digitos[0]][inicial.digitos[1]][inicial.digitos[2]][inicial.digitos[3]] == 0){
		visitados[inicial.digitos[0]][inicial.digitos[1]][inicial.digitos[2]][inicial.digitos[3]] = 1;
		p.push(inicial);

		while(!p.empty()){
			inicial = p.front();
			todos_p(inicial,next);
			p.pop();

			if(compara(inicial,final) == 1){
				/*printf("inicial\n");
				printf("%d %d %d %d\n",inicial.digitos[0],inicial.digitos[1],inicial.digitos[2],inicial.digitos[3]);
				printf("%d %d %d %d\n",final.digitos[0],final.digitos[1],final.digitos[2],final.digitos[3]);*/
				return inicial.pro;
			}

			for (int i = 0; i < 8; ++i){
				if(visitados[next[i].digitos[0]][next[i].digitos[1]][next[i].digitos[2]][next[i].digitos[3]] == 0){
					visitados[next[i].digitos[0]][next[i].digitos[1]][next[i].digitos[2]][next[i].digitos[3]] = 1;
					p.push(next[i]);
				}
			}
		}


	}

	return -1;
} 


int main (){
	int k;
	int visitados[10][10][10][10];

	int n_v;

	cin >> k;

	state inicial;
	state final;
	state aux;


	while(k>0){
		
		scanf("%d %d %d %d",&inicial.digitos[0],&inicial.digitos[1],&inicial.digitos[2],&inicial.digitos[3]);
		inicial.pro = 0;
		scanf("%d %d %d %d",&final.digitos[0],&final.digitos[1],&final.digitos[2],&final.digitos[3]);

		for (int i = 0; i < tam_visitado; ++i){
			for (int j = 0; j < tam_visitado; j++){
				for (int k = 0; k < tam_visitado; k++){
					for (int l = 0; l < tam_visitado; l++){
						visitados[i][j][k][l] = 0;
					}
				}
			}
		}

		scanf("%d",&n_v);

		for (int i = 0; i < n_v; ++i){
			scanf("%d %d %d %d",&aux.digitos[0],&aux.digitos[1],&aux.digitos[2],&aux.digitos[3]);
			visitados[aux.digitos[0]][aux.digitos[1]][aux.digitos[2]][aux.digitos[3]] = 1;
		}

		/*for (int i = 0; i < tam_visitado; ++i){
			for (int j = 0; j < tam_visitado; j++){
				for (int k = 0; k < tam_visitado; k++){
					for (int l = 0; l < tam_visitado; l++){
						if(visitados[i][j][k][l] == 1){
							printf("%d %d %d %d -> %d\n",i,j,k,l,visitados[i][j][k][l]);	
						}
					}
				}
			}
		}*/

		printf("%d\n",bt(inicial,final,visitados));
		getchar();
		
		k--;
	}


	return 0;

}