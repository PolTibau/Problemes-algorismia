#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define DEBUG(CT) {cerr<<#CT<<": ";for(auto vr:CT)cerr<<vr<<", ";cerr<<endl;}
#define debug(vr) {cerr<<#vr<<": "<<vr<<endl;}

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;

int N, M, L;
int start, finish;

vvc V;
vector<vector<vvi>> memo;

ll dp(int n, int m, int l, int s) {
	//cerr << n << " " << m << " " << l << " " << s << endl;
	if (l < 0) return 0;
	if (n == N-1 and m == finish and l >= 0) return 1;
	if (n == N) return 0;

	if (memo[n][m][l][s] != -1) return memo[n][m][l][s];

	memo[n][m][l][s] = 0;
	if (n+1 < N and V[n+1][m] != 'O') memo[n][m][l][s] += dp(n+1, m, l, 0);

	if (s == 0) {
		int mr = m+1;
		while (mr < M and V[n][mr] != 'O') {
			memo[n][m][l][s] += dp(n, mr, l-1, 1);
			mr++;
		}
		int ml = m-1;
		while (0 <= ml and V[n][ml] != 'O') {
			memo[n][m][l][s] += dp(n, ml, l-1, 1);
			ml--;
		}
	}

	return memo[n][m][l][s];
}

int main() {
	while (cin >> N >> M >> L and (N != 0 or M != 0 or L != 0)) {
		V = vvc(N, vc(M));
		vector<pair<int,int>> Old;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				cin >> V[i][j];
				if (V[i][j] == 'O') {
					Old.emplace_back(i, j);
				}
				else if (V[i][j] == 'D') start = j;
				else if (V[i][j] == 'P') finish = j;
			}
		}

		int ans = 0;
		for (auto x : Old) {
			for (int i=x.first-2; i<=x.first+2; i++) {
				for (int j=x.second-2; j<=x.second+2; j++) {
					if (0 <= i and i < N and 0 <= j and j < M) {
						if (V[i][j] == '.') V[i][j] = 'O';
						else if (V[i][j] == 'D') ans = -1;
						else if (V[i][j] == 'P') ans = -1;
					}
				}
			}
		}

		//for(auto x : V) DEBUG(x);
		memo = vector<vector<vvi>>(N, vector<vvi>(M, vvi(L+1, vi(2,-1))));
		if (ans == -1 or dp(0, start, L, 0) == 0) cout << "Good bye, Professor Dyer!" << endl;
		else cout << dp(0, start, L, 0) << endl;

	}
}
