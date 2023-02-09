#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using VI = vector<int>;
VI C;
VI V;
int n, A;
bool actiu;

void print(){
	string c = "";
	for(int i = n-1; i >= 0; --i){
		for(int j = 0; j < V[i]; ++j){
			cout << c << C[i];
			c = ",";
		}
	}
}


bool search(int g, int n){
	if(actiu){
		if(g == 0){
			print();
			actiu = false;
			return true;
		}
		if(g - C[n] >= 0){
			V[n]++;
			search(g - C[n], n);
			V[n]--;
		}
		if(n > 0) search(g, n-1);
	}
	return true;
}


int main(){
	while(cin >> n){
		actiu = true;
		C = VI(n);
		V = VI(n, 0);
		for(int i = 0; i < n; ++i) cin >> C[i];
		cin >> A;
		sort(C.begin(), C.end());
		search(A, n-1);
		if(actiu) cout << -1 << endl;
		else cout << endl;
		
	}
}
