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

	int k,i,resultado;
	scanf("%d\n",&k);
	char op[100000];

	while(k>0){

		fgets(op,100000,stdin);
		i = 2;

		resultado = 0;


		if(op[0] == 'S'){

			while(op[i] != '\0'){
				if(op[i] >= '0' && op[i] <= '9'){
					resultado += str_double(op,&i);
				}else{
					i++;	
				}
				
			}
			printf("T %d\n", resultado);

		}else if(op[0] == 'R'){

			resultado = str_double(op,&i);

			while(op[i] != '\0'){
				if(op[i] >= '0' && op[i] <= '9'){
					resultado -= str_double(op,&i);
				}else{
					i++;	
				}
				
			}
			printf("T %d\n", resultado);

		}else{
			printf("E\n");
		}

		k--;
	}


}