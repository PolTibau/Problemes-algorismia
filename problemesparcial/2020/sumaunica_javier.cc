#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int s, n;
VI V;
VVI memo;

// dp(p, s) = existeix un conjunt de C[0 .. p] que sumi S
int dp(int p, int S) {
	if (S < 0) return false;
	if (p == -1 and S != 0) return 0;
	if (p == -1 and S == 0) return 1;
	if (memo[p][S] != -1) return memo[p][S];
	
	int A = dp(p-1, S - V[p]);
	int B = dp(p-1, S);
	if (A == 1 or B == 1) return memo[p][S] = 1;
	else return memo[p][S] = 0;
}

int main(){
	while(cin >> s >> n){
		V = VI(n);
		memo = VVI(n, VI(s+1, -1));
		for(int i = 0; i < n; ++i){
			cin >> V[i];
		}
		//cout << dp(n-1, s) << endl;
		
		vector<int> S;
		int cS = s;
		for (int i=0; i<n; i++) {
			if (dp(n-i-2, cS)) {
				// no agafis el n-i-1 essim
			}
			else if(dp(n-i-2, cS - V[n-i-1])) {
				// agafa el n-i-1 essim
				cS -= V[n - i - 1];
				S.push_back(V[n-i-1]);
			}
		}
		//cout << cS << endl;
		cout << s << " = ";
		int siz = S.size();
		for (int i=0; i<siz; i++) {
			if (i != 0) cout << " + ";
			cout << S[siz-1-i];
		}
		cout << endl;
	}
}
