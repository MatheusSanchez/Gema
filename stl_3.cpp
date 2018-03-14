//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
#include <stack>


using namespace std;		


int main(){

	stack<pair<int,int>> p;
	vector<pair<int,int>> v;
	int i = 0;

	char c;
	int aux,aux2;

	while(1){

		scanf("%d",&aux);
		//printf("%d\n", aux);
		c = getchar();

		if(aux > 0){
			v.push_back(make_pair(aux,aux));
		}else{
			v.push_back(make_pair(aux,(aux*-1)));
		}	
		

		if(c == '\n'){

			aux2 = v.size();

			for (i = 0; i  != aux2; i++){
				p.push(make_pair(v[i].first, v[i].second));

				if(p.top().first > 0){

					aux = p.top().first;
					p.pop();
					
					if( !p.empty() && p.top().first == aux*-1 && p.top().second > 0){
						p.pop();

						if(!p.empty()){
							p.top().second -= aux;
						}

					}else{

						break;
					}
				}
			}
			
			if(p.empty()){
				printf(":-) Matrioshka!\n");
			}else{
				printf(":-( Try again.\n");	
			}
			while(!p.empty()){
				p.pop();
			}

			v.clear();

			
		}

		if(c == EOF){		
			break;
		}


	}

}