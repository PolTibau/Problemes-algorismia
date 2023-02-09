#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> g;
vector<bool> vist;


bool arbre(int i){
	int compte = 0;
	for(int v : g[i]){
		if(vist[v])compte++;
		if(not vist[v]){
			vist[v] = true;
			if(not arbre(v)) return false;
		}
	}
	if(compte > 1) return false;
	return true;
}



int main() {
  int n, m;
  while(cin >> n >> m){
    vist = vector<bool>(n, false);
    g = vector<vector<int>>(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool bosc = true;
	int arbres = 0;
    for(int i = 0; i < n; ++i){
        if(not vist[i]){
			vist[i] = true;
			arbres++;
            if(not arbre(i)) bosc = false;
        }
    }
    if(bosc) cout << arbres << endl;
    else cout << "no" << endl;
  }
}
