#include <stdio.h>

int str_double(char *op, int *i){

	int resultado = 0;

	while(op[*i] != '\0' && op[*i] != '\n' && op[*i] != '\r' && op[*i] != ' '){
		resultado = resultado * 10;
		resultado += op[*i] - 48;

		(*i)++;
	}


	return resultado;
}

int main (){

	int k,i,resultado=0;
	scanf("%d\n",&k);
	char op[100000];

	while(k>0){

		fgets(op,100000,stdin);
		i = 0;

		while(op[i] != '\0'){
			if(op[i] >= '0' && op[i] <= '9'){
				resultado += str_double(op,&i);
			}else{
					i++;	
			}
				
			}
			
		k--;
	}

	printf("%d\n", resultado);
}