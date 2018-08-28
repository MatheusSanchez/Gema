#include <bits/stdc++.h>

#define true 1
#define false -1
#define inf 0x3f3f3f3f // numero grandão

#define ll long long

using namespace std;

typedef vector<int> vi; // vector int

typedef pair<int ,int> p_i; // pair int
typedef vector<p_i> v_p_i; // vector pair int
typedef vector<v_p_i> graph; // vector de vector pair int; (lista de adjacencia) 


int main (){

	ios :: sync_with_stdio(false);

	int n,n1,n2,aux;

	cin >> n;

	if(n>0){
		cout << n << endl;
		return 0;
	}

	aux = n%10; 

	n /= 10;
	n1 = n;

	n /= 10;
	n2 = n*10 + aux;

	//cout << n1 << " " << n2 << endl;

	cout << max(n1,n2) << endl;



}