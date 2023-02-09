#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;

vector<vector<vector<vector<vector<vvi>>>>> memo;

ll dp(int a, int b, int c, int d, int e, int f, int j) {
	if (a == 0 and b == 0 and c == 0 and d == 0 and e == 0 and f == 0) return 0;
	if (memo[a][b][c][d][e][f][j] != -1) return memo[a][b][c][d][e][f][j];
	for (int ia=0; ia < a; ia++) {
		memo[a][b][c][d][e][f][j] = max(memo[a][b][c][d][e][f][j], 1^dp(ia,b,c,d,e,f,j^1));
	}
	for (int ib=0; ib < b; ib++) {
		memo[a][b][c][d][e][f][j] = max(memo[a][b][c][d][e][f][j], 1^dp(a,ib,c,d,e,f,j^1));
	}
	for (int ic=0; ic < c; ic++) {
		memo[a][b][c][d][e][f][j] = max(memo[a][b][c][d][e][f][j], 1^dp(a,b,ic,d,e,f,j^1));
	}
	for (int id=0; id < d; id++) {
		memo[a][b][c][d][e][f][j] = max(memo[a][b][c][d][e][f][j], 1^dp(a,b,c,id,e,f,j^1));
	}
	for (int ie=0; ie < e; ie++) {
		memo[a][b][c][d][e][f][j] = max(memo[a][b][c][d][e][f][j], 1^dp(a,b,c,d,ie,f,j^1));
	}
	for (int iif=0; iif < f; iif++) {
		memo[a][b][c][d][e][f][j] = max(memo[a][b][c][d][e][f][j], 1^dp(a,b,c,d,e,iif,j^1));
	}
	return memo[a][b][c][d][e][f][j];
}

int main() {
	int T;
	cin >> T;
	memo = vector<vector<vector<vector<vector<vvi>>>>>(7, vector<vector<vector<vector<vvi>>>>(7,
			vector<vector<vector<vvi>>>(7, vector<vector<vvi>>(7, vector<vvi>(7, (vvi(7, vi(2, -1))))))));
	for (int t=1; t<=T; t++) {
		string A, B;
		int a,b,c,d,e,f;

		cin >> A >> B >> a >> b >> c >> d >> e >> f;
		cout << "Joc #" << t << ": ";
		if (dp(a,b,c,d,e,f,0) == 1) cout << A << endl;
		else cout << B << endl;
	}
}
