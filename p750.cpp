#include <bits/stdc++.h>

using namespace std;

int vale(int c[][8],int coluna,int linha){

	if(c[coluna][linha] == 1){
		for (int i = 0; i < 8; ++i){
			if(c[coluna][i] == 3){
				return 0;
			}
		}
		return 1;
	}else{
		return 0;
	}

}

int da_pra_ir(int c[][8]){

	int aux = 0;

	for (int i = 0; i < 8; ++i){
		aux = 1;
		for (int j = 0; j < 8; ++j){
				if(c[i][j] == 1){
					aux = 0;
					break;
				}
		}
		if(aux == 1){
			return -45;
		}
	}

	return 45;

}


void bt(int c[][8], int n_q, int c_atual){

	if(n_q == 8){
		cout << "Really men ?" << endl;

		for (int i = 0; i < 8; ++i){
			for (int j = 0; j < 8; ++j){
				cout << c[i][j] << ' ';
			}
			cout << endl << endl;
		}
	}else if(da_pra_ir(c)){
		for (int i = 0; i < 8; ++i){
			if(vale(c,c_atual,i)){

				for (int j = 0; j < 8; j++){ 
					c[j][i] = 0;
					c[j][c_atual+i] = 0;
				}
				
			}
			
		}
		bt(c,n_q+1,c_atual+1);
	
	}
}

int main(){


	int k;

	cin >> k; 
	int c[8][8];


	while(k > 0){

		int a,b;

		cin >> a >> b;

		for (int i = 0; i < 8; ++i){
			for (int j = 0; j < 8; ++j){
				c[i][j] = 1;
			}
		}

		

		for (int j = 0; j < 8; ++j){ 
				c[j][a - 1] = 0;
				c[j][a-1+j] = 0;
		}

		c[a - 1][b - 1] = 3; 

		for (int i = 0; i < 8; ++i){
			for (int j = 0; j < 8; ++j){
				cout << c[i][j] << ' ';
			}
			cout << endl << endl;
		}


		bt(c,1,0);


		k--;
	}


}