#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
cons int MOD = 1e9+7;
int n;
VI memo;

//retorna les combinacions si a la posicio n hi ha un dimoni
int dimoni(int n){
	if(n == 1) return 1;
	if(dimoni[n] != -1)return dimoni[n];
	int& q = dimoni[n];
	return q = dimoni[n-1]; 
}


//retorna les combinacions si a la posicio n hi ha una angel
int angel(int n){
	if(n == 1) return 1;
	if(n == )
}

int main(){
	cin >> n;
	memo = VI(1e5+2, -1);
	dimoni[0] = 0;
	dimoni[1] = 1;
	angel[0] = 0;
	angel[1] = 1;
	for(int i = 0; i < 1e5+1; ++i)memo[i] = dimoni[i] + angel[i];
	cout << memo[n] << endl;
}
