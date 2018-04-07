#include <iostream>
#include <vector>

using namespace std;


int bt(int total,int i_v,int soma, vector<int> nums,vector<int> perm){
	
	if(total == soma){
		//cout << "Size " << perm.size() << endl;
		int tam  = perm.size();
		for (int i = 0; i < tam; ++i){
			cout << perm[i];
			if(i == tam - 1){
				cout << endl;
			}else{
				cout << '+';
			}
		}
		return 1;
	}

	int retorno = 0;
	int ant = 150;
	int atual = 0;
	int tam = nums.size();
	for (; i_v < tam; i_v++){

		 atual = nums[i_v];
		
		if(soma+atual <= total && atual != ant){
			
			perm.push_back(nums[i_v]);
			retorno += bt(total,i_v+1,soma+atual,nums,perm);
			perm.erase (perm.end()-1);
			ant = atual;


		}
		 
	}

	return retorno;

}



int main (){


	vector<int> v;

	int total;
	int size;
	int aux;

	while(1){
		cin >> total;
		cin >> size;

		if(size == 0){
			break;
		}


		for (int i = 0; i < size; ++i){
			cin >> aux;
			v.push_back(aux);
		}

		vector<int> perm;
		cout << "Sums of " << total << ":\n"; 
		int retorno = bt(total,0,0,v,perm);
		
		if(retorno == 0){
			cout << "NONE" << endl; 
		}

		v.clear();
		perm.clear();	
	}

	



}