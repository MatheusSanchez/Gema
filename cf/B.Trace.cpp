#include <bits/stdc++.h>
#define PI 3.1415926536

using namespace std;

int main (){

	ios :: sync_with_stdio(false);

	int n,x;
	double sum = 0;

	vector<int> v;
	cin >> n;

	while(n--){
		cin >> x;
		v.push_back(x);
	}

	sort(v.rbegin(),v.rend());

	for (int i = 0; i < v.size(); i+=2){

		sum += pow(v[i],2);
	}
	for (int i = 1; i < v.size(); i+=2){
		sum -= pow(v[i],2);
	}

	cout << sum * PI << endl;

}