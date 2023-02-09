#include<iostream>
#include<vector>
using namespace std;

int g, n;
using ll = long long;
using VI = vector<int>;
int maxim, iaies;
VI E, C;

void evalua(){
	int iaies = 0;
	for(int k = 0; k < n; ++k){
		if(C[k]){
			iaies += E[k];
			if(k-1 >= 0 and not C[k-1]) iaies += E[k-1]/2;
			if(k+1 < n and not C[k+1]) iaies += E[k+1]/2;
		}
	}
	maxim = max(maxim, iaies);
}



void save_grannies(int g, int k){
	if(n - k < g) return;
	if(g == 0){
		maxim = max(maxim, iaies);
		return;
	}
	
	int add = 0;
	if(C[k] == 1) add += E[k]/2;
	else add += E[k];
	C[k] = 2;
	if(k-1 >= 0 and not C[k-1]) add += E[k-1]/2;
	if(k+1 < n){
		C[k+1] = 1;
		add += E[k+1]/2;
	}
	iaies += add;
	save_grannies(g-1, k+1);
	iaies -= add;
	C[k] = 0;
	if(k-1 >= 0) C[k-1]--;
	if(k+1 < n) C[k+1]--;
	
	save_grannies(g,k+1);
}





int main(){
	while(cin >> g >> n){
		E = VI(n);
		C = VI(n, 0);
		for(int i = 0; i < n; ++i){
			cin >> E[i];
		}
		maxim = 0;
		save_grannies(g, 0);
		cout << maxim << endl;
	}
}
