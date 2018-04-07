//#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <iostream>
#include <bitset>
#include <stdio.h>

#define size_max 1000

using namespace std;

int main (){
	
	vector <int> primos;

	bitset<1000> bt; // todos numeros
	
	bt.set();
	bt[0] = 0; 
	bt[1] = 0;

	map<int,int> resp;	

	for (int i = 2; i < size_max; ++i) // alg crivos
	{
		if(bt[i] == 1){
			primos.push_back(i);
			for (int j = i*i; j < size_max; j += i){
				bt[j] = 0;
			}
		}
	}

	

	int fat = 45; // pq sim
	/*for (int i = 0; i < primos.size(); ++i){
		cout << primos[i] << " " ;
	}
	cout << '\n';*/

	cin >> fat;	

	
	while(fat != 0){

		
		int num = 2;
		int aux = 2;

		while(aux <= fat){
			num = aux;

			for (int i = 0; num > 1; ++i){
				//cout << num << " - " << primos[i] << '\n';
				if(num % primos[i] == 0){
					num = num / primos[i];
					resp[i]++;
					i--;
				
				}	
			}

			aux++;
		}


		printf("%3d! =", fat);
		aux = resp.size();
		for (int i = 0; i < aux; ++i){
			if(i % 15 == 0 && i > 0){
				printf("\n      ");
			}
			printf(" %2d", resp[i]);
			
			
		}
	

		cout << '\n';
		
		resp.clear();
		cin >> fat;	
		
	}

	

	
	
}