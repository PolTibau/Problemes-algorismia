#include <iostream>
#include <vector>
#include<string>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;
int n;
string s, t;
VVI D;
VI C;


int min3(int a, int b, int c) {
  return min(a, min(b, c));
}

int acaba(int i, int j){
	int valor = 0;
	if(i == 0){
		for(int x = 0; x < j; ++x) valor += C[t[x] - 'a'];
	}
	else if(j == 0){
		for(int x = 0; x < i; ++x) valor += C[s[x] - 'a'];
	}
	return valor;
}


// Cost minim de fer s[0..i-1] igual a t[0..j-1].
int f(int i, int j) {
  int& res = D[i][j];
  if (res != -1) return res;
  if (i == 0) return acaba(i, j);
  if (j == 0) return acaba(i, j);
  if (s[i-1] == t[j-1]) return res = f(i - 1, j - 1);
  return res = min3(f(i, j - 1) + C[t[j-1] - 'a'], f(i - 1, j) + C[s[i-1] - 'a'], f(i - 1, j - 1) + C[s[i-1] - 'a'] + C[t[j-1] - 'a']);
}


int main() {
  while(cin >> n){
	C = VI(n);
	for(int i = 0; i < n; ++i) cin >> C[i];
	cin >> s >> t;
    D = VVI(s.size() + 1, VI(t.size() + 1, -1));
    cout << f(s.size(), t.size()) << endl;
  }
}
