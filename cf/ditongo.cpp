#include <bits/stdc++.h>
	
using namespace std;


int main (){

	string resp = "";
	char c;
	c = getchar();
	int tira = 0;

	while(c != EOF){
		//cout << c;
		//exit(0);
		if((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')){
			if(tira == 0){
				tira = 1;
				resp += c;
			}	
		}else{
			tira = 0;
			resp += c;
		}

		c = getchar();
	}



	cout << resp << endl;

}