#include<iostream>
#include<vector>
using namespace std;

const int N = 500000;
using VI = vector<int>;
int n;
VI dp;

int compara( int x, int y, int z, int t){
	int minim;
	minim = min(x, min(y, min(z, t)));
	return minim;
}


int comb(int n){
	if(n < 0) return N;
	int& q = dp[n];
	if(q != -1) return dp[n];
	else q = compara(comb(n-1)+1, comb(n-5)+1, comb(n-8)+1, comb(n-14)+1);
	return dp[n] = q;
	
}




int main(){
	dp = VI(N+1, -1);
	dp[0] = 0;
	dp[1] = dp[5] = dp[8] = dp[14] = 1;
	while(cin >> n  and n != -1){
		cout << comb(n) << endl;
	}
}
