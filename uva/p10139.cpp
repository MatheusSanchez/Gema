//#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <iostream>
#include <bitset>
#include <stdio.h>
			
#define MAX 47000
				
#define ll long long
#define pb push_back

using namespace std;

int divide(int fatorial,int divisor,vector< pair<int,int> > v){

	vector< pair<int,int> >:: iterator it;

	for (it = v.begin(); it != v.end(); it++){
		ll num = it->first;
		//cout << (num) << " " << it->second << endl;
		while(it->second > 0 && num <= fatorial){
			
			it->second -= (fatorial/num);
			num = num* (it->first);
		}

		if(it->second > 0){
			return -41;	
		}
	}

	return 15;

}

//123456873
//123456789

int main (){
	bitset<MAX> v;
	v.set();
	v[0] = 0;
	v[1] = 0;
	v[2] = 1;
	int i = 2;

	vector<int> primos;
	vector<int>:: iterator it_primos;
	primos.push_back(2);

	while(i*2 < MAX){ // crivo otmizado
		i = i*2;
		v[i] = 0;
	}

	for (i = 3; i < MAX; i+=2){
		
		if(v[i] == 1){
			primos.push_back(i);
			for (int j = i*2; j < MAX; j+=i){
				v[j] = 0;
			}

		}		
	}


	int fatorial,divisor;
	
	while(cin >> fatorial >> divisor){	

		if(divisor == 0){
			cout << divisor <<  " does not divide " << fatorial << "!" << endl;

		}else if(fatorial >= divisor){
			cout << divisor <<  " divides " << fatorial << "!" << endl;
		}else{
				int numero = divisor;
		int aux = 0;	

		vector< pair<int,int> > div_f;
		vector< pair<int,int> >::iterator it;

		for (it_primos = primos.begin(); it_primos != primos.end(); it_primos++){
			while(numero > 1 && numero % (*it_primos) == 0){
					numero = numero / (*it_primos);
					
					aux++;
					
			}
			if(aux != 0){
				//cout << (*it_primos) << "->" << aux << endl;
				div_f.pb(make_pair((*it_primos),aux));
			}
			aux = 0;
		}
	
		if(numero>2){
			//cout << "Easdadsasd" << endl;
			div_f.pb(make_pair(numero,1));
		}


		if(divide(fatorial,divisor,div_f) == 15){
			cout << divisor <<  " divides " << fatorial << "!" << endl;
		}else{
			cout << divisor <<  " does not divide " << fatorial << "!" << endl;
		}

		div_f.clear();
		}

	
	}	
	return 0;
}
