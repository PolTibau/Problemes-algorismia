#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e8+7;
using VI = vector<int>;
using VVI = vector<VI>;
VVI camins;
int n;

int troba_camins(int i, int k){
	if(k > i)return 0;
	if(i == 1)return 1;
	int& q = camins[i][k];
	if(q != -1) return q;
	if(k == 0)return q = (troba_camins(i-1, k+1)%MOD + troba_camins(i-1, k)%MOD)%MOD;
	if(k != 0)return q = (troba_camins(i-1, k+1)%MOD + troba_camins(i-1, k-1)%MOD + troba_camins(i-1, k)%MOD)%MOD;
	return -1;
}


int main(){
	camins = VVI(2001, VI(2001,-1));
	camins[0][0] = 1;
	while(cin >> n){
		if(camins[n][0] == -1)cout << troba_camins(n, 0) << endl;
		else cout << camins[n][0] << endl;
	}
}
