#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct aresta{
    int u;
    int v;
    int c;
};
using P = pair<aresta, bool>;
using VI = vector<int>;
using VA = vector<P>;
VA A;
VI pare;
int n, m;


bool comp(pair<aresta,bool>& x, pair<aresta,bool>& y){
    return x.first.c > y.first.c;
}

int repre(int x) {
  if (pare[x] == -1) return x;
  int r = repre(pare[x]);
  pare[x] = r;
  return r;
}

bool es_connex_sense(){
  pare = VI(n, -1);
  int compo = n;
  for(pair<aresta,bool> a : A){
		if(not a.second)continue;
    int x = a.first.u;
    int y = a.first.v;
    int rx = repre(x);
    int ry = repre(y);
    if (rx != ry){
      pare[ry] = rx;
      if (--compo == 1) return true;
    }
  }
  return false;
}



int main(){
    while(cin >> n >> m){
        A = VA(m);
				int suma = 0;
        int u, v, c;
				int minim = 0;
				int maxim = 0;
        for(int i = 0; i < m; ++i){
					aresta a;
					cin >> u >> v >> c;
					a.u = u;
					a.v = v;
					a.c = c;
					A[i] = P(a, true);
					suma += c;
        }
				int actives = m;
        sort(A.begin(), A.end(), comp);
				for(int i = 0; actives >= n-1 and A[i].first.c >= 0 and i < m; ++i){
					A[i].second = false;
					if(A[i].first.c > 0 and es_connex_sense()){
						++minim;
						++maxim;
						suma -= A[i].first.c;
						--actives;
					}
					else if(A[i].first.c == 0 and es_connex_sense()){
						++minim;
						suma -= A[i].first.c;
						--actives;
					}
					else A[i].second = true;
				}
				
				cout << suma << ' ' << m-minim << ' ' << m-maxim << endl;
    }
}
