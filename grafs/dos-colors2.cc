#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<int> pinta;


bool coloreja(int u) {
  for (int v : g[u]){
      if(pinta[v] == -1){
		  if(pinta[u] == 1) pinta[v] = 0;
		  else pinta[v] = 1;
		  if(not coloreja(v)) return false;;
	  }
	  else if(pinta[v] == pinta[u]) return false;
  }
  return true;
}

void pinta_primer(int i){
	pinta[i] = 1;
}

int main() {
  int n, m;
  while(cin >> n >> m){
    pinta = vector<int>(n, -1);
    g = vector<vector<int>>(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool colorejable = true;
    for(int i = 0; i < n; ++i){
        if(pinta[i] == -1){
			pinta_primer(i);
            if(not coloreja(i)) colorejable = false;
        }
    }
    if(colorejable) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}
