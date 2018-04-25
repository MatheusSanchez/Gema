#include <bits/stdc++.h>

using namespace std;


int main(){

	string num;
	string resul;

	cin >> num;

	while(num.compare("-1") != 0){
		if(num.compare("0") != 0){
			for (int i = num.size()-1; i >= 0; i--){
				if(num[i] >= 49){
					cout << "Aoba" << (num[i] - 1);
					num[i] = char(num[i] - 1);
					break;
				}else{
					num[i] = '9';	
				}	
			}
			int i = 0;

			while(num[i] == '0'){
				i++;
			}

			resul = num.substr(i);

			cout << resul << endl;
		}else{
			cout << "0" << endl;
		}
		
		cin >> num;
	}



}