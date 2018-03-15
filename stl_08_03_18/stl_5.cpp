

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
#include <stack>
#include <stdio.h>

using namespace std;		

typedef struct time{

	string nome;

	int pontos,w,l,t,gols_f,gols_t;

	void init_s(){
		pontos = w = l = t = gols_f = 0;
		gols_t = 0;
	}

	void joga(int t1,int t2){
		if(t1 > t2){
			w++;
			pontos+=3;
		}else if(t1 < t2){
			l++;

		}else{
			t++;
			pontos++;
		}
		gols_f += t1;
		gols_t += t2;
	}		

}t_time;


bool compara (t_time a, t_time b) {
    if(a.pontos != b.pontos)    return a.pontos > b.pontos;
    if(a.w != b.w)  return a.w > b.w;

    if(a.gols_f - a.gols_t != b.gols_f - b.gols_t)
        return a.gols_f - a.gols_t > b.gols_f - b.gols_t;

    if(a.gols_f != b.gols_f) return a.gols_f > b.gols_f;

    if(a.w+a.l+a.t != b.w+b.l+b.t)
        return b.w+b.l+b.t  > a.w+a.l+a.t;

    return a.nome.compare(b.nome) < 0;
}

int main(){

	map <string,int> tab;
	map <string,int>::iterator it;
	t_time times[500];

	int n,n_times,n1,n2,n_jogos;
	string torneio;
	char t1[50],t2[50];
	string jogo;

	cin >> n;
	getchar();

	while(n>0){

		getline(cin,torneio);
		cin >> n_times;
		getchar(); 
		cout << torneio << '\n';

		for (int i = 0; i < n_times; ++i){
			times[i].init_s();
			getline(cin,times[i].nome); 
			tab[times[i].nome] = i;
		}

		cin >> n_jogos;
		getchar();
		
		for (int i = 0; i < n_jogos; ++i){
			getline(cin,jogo);
		
			char * jogoc = new char[jogo.size() + 1];
			std::copy(jogo.begin(), jogo.end(), jogoc);
			jogoc[jogo.size()] = '\0';

			sscanf(jogoc,"%[^#]#%d@%d#%[^\n]",t1,&n1,&n2,t2);
	
		
			times[tab[t1]].joga(n1,n2);
			times[tab[t2]].joga(n2,n1);


		}
		
		 sort(times, times+n_times, compara);

		 for(int i = 0; i < n_times; i++){

		 	char * jogoc = new char[times[i].nome.size() + 1];
			std::copy(times[i].nome.begin(), times[i].nome.end(), jogoc);
			jogoc[times[i].nome.size()] = '\0';

            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                    i+1, jogoc, times[i].pontos, times[i].w+times[i].l+times[i].t,
                    times[i].w, times[i].t, times[i].l, times[i].gols_f-times[i].gols_t,
                  	times[i].gols_f, times[i].gols_t);
		
		}


		n--;
		tab.clear();
		if(n>0){
			printf("\n");
		}
	
	}

}