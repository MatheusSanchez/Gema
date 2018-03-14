#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main (){

	int num,n1,n2;
	int pilha,fila,p_fila;

	

	stack<int> s;
	queue<int> q;
	priority_queue<int> p_q;

	while(cin >> num){

		pilha = fila = p_fila = 1;
		while(!s.empty()){
			s.pop();
		}
		while(!q.empty()){
			q.pop();
		}
		while(!p_q.empty()){
			p_q.pop();
		}
		for (int i = 0; i < num; ++i){

			cin >> n1;
			cin >> n2;

			if(n1 == 1){

				s.push(n2);
				q.push(n2);

				if(p_fila == 1){
					p_q.push(n2);
				}

			}else{
				if(pilha == 1){
					if(s.top() == n2){
						s.pop();
					}else{
						pilha = 0;
					}
				}

				if(p_fila == 1){
					if(p_q.top() == n2){
						p_q.pop();
					}else{
						p_fila = 0;
					}
				}

				if(fila == 1){
					if(q.front() == n2){
						q.pop();
					}else{
						fila = 0;
					}
				}
			}
		}

		if(p_fila == 0 && fila == 0 && pilha == 0){
			cout << "impossible" << '\n';
		}else if(p_fila + fila + pilha > 1){
			cout << "not sure" << '\n';
		}else{
			if(p_fila == 1){
				cout << "priority queue" << '\n';
			}else if(fila == 1){
				cout << "queue" << '\n';	
			}else if(pilha == 1){
				cout << "stack" << '\n';
			}

		}
	}


}