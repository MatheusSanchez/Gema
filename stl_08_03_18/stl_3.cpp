#include <bits/stdc++.h>

using namespace std;		


int main(){
	

	stack< pair<int,int> > p;
	vector< pair<int,int> > v;

	int i = 0;

	char c;
	int aux,aux2;
	int ve;
	
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
			
			ve = 1;
			aux2 = v.size();

			for (i = 0; i  != aux2; i++){
				
				p.push(make_pair(v[i].first, v[i].second));

				if(p.top().first > 0){
					aux = p.top().first;
					p.pop();

					if(aux * (-1) == p.top().first){
						p.pop();

						if(!p.empty()){
							p.top().second -= aux;
						}
						

						if(!p.empty() && p.top().second <= 0){
							cout  << ":-( Try again.\n";
							ve = 0;
							break;
						}

					}else{
						cout  << ":-( Try again.\n";
						ve = 0;
						break;
					}
					
				}

			}
			
			if(p.empty() && ve == 1){
				cout << ":-) Matrioshka!\n";
			}else if(ve == 1){
				cout << ":-( Try again.\n";	
			}
		
			while(!p.empty()){
				p.pop();
			}

			v.clear();

			
		}else if(c == EOF){		
			ve = 1;
			aux2 = v.size();

			for (i = 0; i  != aux2; i++){
				
				p.push(make_pair(v[i].first, v[i].second));

				if(p.top().first > 0){
					aux = p.top().first;
					p.pop();

					if(aux * (-1) == p.top().first){
						p.pop();

						if(!p.empty()){
							p.top().second -= aux;
						}
						

						if(!p.empty() && p.top().second <= 0){
							cout  << ":-( Try again.\n";
							ve = 0;
							break;
						}

					}else{
						cout  << ":-( Try again.\n";
						ve = 0;
						break;
					}
					
				}

			}
			
			if(p.empty() && ve == 1){
				cout << ":-) Matrioshka!\n";
			}else if(ve == 1){
				cout << ":-( Try again.\n";	
			}
		
			while(!p.empty()){
				p.pop();
			}

			v.clear();

			break;
		}


	}

}