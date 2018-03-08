#include <stdio.h>

int main (){

	int resultado = 0,aux=0,aux2=0;

	while(scanf("%d %d",&aux,&aux2) != EOF){
		resultado += aux + aux2;
	}

	printf("%d\n", resultado);
}