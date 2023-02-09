#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct aresta{
    int u;
    int v;
    int c;
};

using P = pair<int, int>;
using VP = vector<P>;
using VE = vector<int>;
using VA = vector<aresta>;
VA A;
VE pare;
int n, m;


bool comp(aresta& x, aresta& y){
    return x.c < y.c;
}

int repre(int x) {
  if (pare[x] == -1) return x;
  int r = repre(pare[x]);
  pare[x] = r;
  return r;
}


int minim(){
  int compte = 0;
  pare = VE(n, -1);
  int compo = n;
  for (aresta a : A) {
    int x = a.u;
    int y = a.v;
    int rx = repre(x);
    int ry = repre(y);
    if (rx != ry) {
      pare[ry] = rx;
      compte += a.c;
      if (--compo == 1) return compte;
    }
  }
  return -1;
}



int main(){
    while(cin >> n >> m){
        A = VA(m);
        int u, v, c;
        for(aresta& a: A){
            cin >> u >> v >> c;
            a.u = u-1;
            a.v = v-1;
            a.c = c;
        }
        sort(A.begin(), A.end(), comp);
				if(minim() == -1)cout << 0 << endl;
        else cout << minim() << endl;
    }
}
