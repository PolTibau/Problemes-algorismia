#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int INF = 1000000000;
typedef vector<int> VI;
typedef vector<VI> VVI;


int n, m;
VVI G;
int C[1000];


bool OK1(VVI A) {
  for (int x = 0; x < n; ++x) A[x][x] = 0;

  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        A[i][j] = min(A[i][j],
                      A[i][k] + A[k][j]);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (A[i][j] == INF) return false;
  return true;
}

bool OK2(int i) {
  cout << i << endl;
  if (i == n){
		cout << "true" << endl;
		return true;
	}
  vector<bool> U(2, false);
  for (int j = 0; j < i; ++j)
    if (G[i][j] == 1) U[C[j]] = true;

  for (int k = 0; k < 2; ++k){
		cout << k << ' ' << U[k] << endl;
    if (not U[k]) {
      C[i] = k;
      if (OK2(i + 1)) return true;
    }
	}
	cout << "false" << endl;
  return false;
}


int main() {
  while (cin >> n >> m) {
    G = VVI(n, VI(n, INF));
    while (m--) {
      int x, y;
      cin >> x >> y;
      G[x][y] = G[y][x] = 1;
    }

    if (not OK1(G)) cout << "NC" << endl;
    else if (OK2(0)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}
