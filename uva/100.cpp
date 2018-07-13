#include <bits/stdc++.h>

int s_nums[3000001];

long long aux;

int calc (long long k){

	//printf("%lld ", k);

	if(k == 1){
		aux++;		
		return aux;
	}
	if(s_nums[k] != -1){
		//printf("aqui, k %d\n", k);		
		return s_nums[k]+aux;
	}

	if(k%2 == 0){
		aux++;
		return calc(k>>1);
	}else{
		aux+=2;
		printf("%lld\n", ((3*k)+1)>>1);
		return calc(((3*k)+1)>>1);	
	}

	

}


int main (){

	memset(s_nums,-1,sizeof s_nums);
	s_nums[1] = 1;
	s_nums[2] = 2;
	long long i,j;
	
	while(scanf("%lld %lld",&i,&j) != EOF){
		
		if(i > j){
			aux = i;
			i = j;
			j = aux;
		}

		int resp1,resp2,maior;
		maior=0;
		resp1 = i;
		resp2 = j;

		while(i <= j){
			aux = 0;
			if(s_nums[i] == -1){
				s_nums[i] = calc(i);
			}
			
			aux = s_nums[i];

			if(aux > maior){
				maior = aux;
			}
			printf("%lld\n", i);
			i++;
			/*if(i>10){
				exit(0);
			}*/
			
		
		}


		printf("%d %d %d\n",resp1,resp2,maior );
		//exit(0);
	}



}