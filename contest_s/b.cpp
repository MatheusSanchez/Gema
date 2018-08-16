#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;

typedef vector<int> vi;
typedef long long ll;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> graph;


int main (){

	ios :: sync_with_stdio(false);

	int i1,i2;

	string p1,p2;
	cin >> p1 >> p2;

	i1 = p1.size() - 1;
	i2 = p2.size() - 1;

	if(p1[i1] != p2[i2]){
		cout << p1.size() + p2.size() << endl;
	}else{

		while(p1[i1] == p2[i2] && i1 >= 0 && i2 >= 0){
			i1--;
			i2--;
		}
		if(i1 >= 0 && i2 >= 0){
			cout << i1+i2+2 << endl;
		}else if(i1 < 0){
			cout << i2+1 << endl;
		}else{
			cout << i1+1 << endl;
		}
		
	}

}