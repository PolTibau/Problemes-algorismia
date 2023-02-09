#include<iostream>
#include<vector>
#include<string>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
string s;
VVI dp;

int f(int i, int j){
	if(i >= j) return 0;
	int& q = dp[i][j];
	if(q != -1) return q;
	if(s[i] == s[j]) return q = f(i+1, j-1);
	return q = 1 + min(f(i+1, j), f(i, j-1));
}


int main(){
	while(cin >> s){
		int n = s.size();
		dp = VVI(n, VI(n, -1));
		int t = f(0, n-1);
		if(t == 0) cout << "Passes the Dislex-Wonga test" << endl;
		else cout << t << endl;;
	}
}
