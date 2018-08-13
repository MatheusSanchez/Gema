#include <bits/stdc++.h>

using namespace std;

char mat[10][10];
char visit[10][10];
int l,c,ini;

void p_m(){
	for (int i = 0; i < l; ++i){
		for (int j = 0; j < c; ++j){
		cout << visit[i][j] << " ";
	    }
	    cout << endl;
	}
}

int deu_ruim(int i,int j, int count,int aux){

	if(visit[i][j] == '0' && aux == 1){
		return count;
	}

	if(mat[i][j] == 'W'){
		j--;
	}else if(mat[i][j] == 'E'){
		j++;
	}else if(mat[i][j] == 'N'){
		i--;
	}else if(mat[i][j] == 'S'){
		i++;
	}

	return deu_ruim(i,j,count+1,1);

}


void run(int i,int j, int count){

	if(i < 0 || j < 0 || i >= l || j >= c){
		cout << count << " step(s) to exit" << endl;
		return;
	}else if(visit[i][j] == '1'){
		visit[i][j] = '0';
		//cout << "deu ruim; "<< i << " "<< j << endl;
		//p_m();
		int loop =  deu_ruim(i,j,0,0);
		cout << count - loop << " step(s) before a loop of " << loop << " step(s)" << endl;	
		return;
	}
	visit[i][j] = '1';

	if(mat[i][j] == 'W'){
		j--;
	}else if(mat[i][j] == 'E'){
		j++;
	}else if(mat[i][j] == 'N'){
		i--;
	}else if(mat[i][j] == 'S'){
		i++;
	}
	//p_m();

	
	return run(i,j,count+1);

}




int main(){

	ios :: sync_with_stdio(false);

	

	cin >> l >> c >> ini;

	while(ini != 0){

		for (int i = 0; i < 10; ++i){		
			for (int j = 0; j < 10; j++){
				mat[i][j] = 'i';
				visit[i][j] = '0';
			}
		}	

		for (int i = 0; i < l; ++i){
			for (int j = 0; j < c; j++){
				cin >> mat[i][j];
			}
		}
		run(0,ini-1,0);
		cin >> l >> c >> ini;
	}


	


}