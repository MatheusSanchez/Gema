//#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
	
using namespace std;

int main (){

	vector<int> v;
	vector<int>::iterator p;
	vector<int>::reverse_iterator rp;

	
	int aux;

	while(scanf("%d",&aux) != EOF){	
		v.push_back(aux);
	}

	sort(v.begin(),v.end());

	for (p = v.begin(); p != v.end(); p++){
		printf("%d\n", *p);
	}


	printf("\n");

	for (rp = v.rbegin(); rp != v.rend(); rp++){
		printf("%d\n", *rp);
	}
}