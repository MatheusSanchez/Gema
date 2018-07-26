
/*programa que constrói todas as possiveis palavras com 5 letras*/
// através de backtracking

#include <bits/stdc++.h>

#define max 3 // numero máximo de letras na palavra
#define inf 0x3f3f3f3f

using namespace std;

void backtracking (char *palavra, int k){

	if (k == max){  // condição de parada

		printf("%s\n", palavra);

	}else{

		for (char i = 'a'; i <= 'z'; ++i){ 
			palavra[k] = i;	
			backtracking(palavra,k+1); // gera a solução parcial e chama para a proxima letra
		}

	}
}


int main (){

	char palavra[max+1]; // palavra a ser gerada
	palavra[max] = '\0';	
	backtracking(palavra,0); // vetor e indice da letra atual

}