#include <bits/stdc++.h>
using namespace std;

char tmp[400];
set<string> v;
int n;
char tab[20][20];
int u[20][20];


void bt(int i, int j, int ind){

	if(ind >= 3){
		tmp[ind] = '\0';
		v.insert(tmp);
		//return;
	}

	if(i < 0 || j < 0 || j >= n || i >= n){
		return;
	}

	if(ind > 0 && tab[i][j] <= tmp[ind-1]){
        return;
	}

	if(u[i][j] == 1){
		return;
	}

	tmp[ind] = tab[i][j];
	u[i][j] = 1;

	bt(i+1,j+1,ind+1);
	bt(i+1,j-1,ind+1);
	bt(i-1,j+1,ind+1);
	bt(i-1,j-1,ind+1);

	bt(i+1,j,ind+1);
	bt(i-1,j,ind+1);
	bt(i,j+1,ind+1);
	bt(i,j-1,ind+1);

	u[i][j] = 0;
}

bool cmp(string a, string b) {
    return a.length() < b.length();
}

int main (){

	ios::sync_with_stdio(false);

	int cases;
	cin >> cases;

	for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				u[i][j] = 0;
		}
	}

	while(cases){

		
		cin >> n;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				cin >> tab[i][j];
			}
		}

		v.clear();
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				bt(i,j,0);
			}	
		}

		string resp[100000];
		int id = 0;
		for (set<string>:: iterator i = v.begin(); i != v.end() ; i++){
			resp[id++] = *i;
		}

		stable_sort(resp,resp+id,cmp);

		for (int i = 0; i < id; ++i)	{
			cout << resp[i] << endl;
		}
		if(cases > 1){
			cout << endl;
		}
		
		//resp.clear();
		
		cases--;	
	}


}