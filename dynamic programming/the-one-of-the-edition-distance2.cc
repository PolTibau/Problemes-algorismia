#include <iostream>
#include <vector>
#include<string>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;
int n, minim;
string s, t;
VVI D;
VI C;


int min5(int a, int b, int c, int d, int e) {
  return min(a, min(b, min(c, min(d, e))));
}

int acaba(int i, int j){
	int valor = 0;
	if(i == 0){
		for(int x = j-1; x >= 0; --x){
			int change2 = (minim + C[t[x] - 'a']+3)/4;
			valor += min(C[t[x] - 'a'], minim + change2);
		}
	}
	else if(j == 0){
		for(int x = 0; x < i; ++x){
			int change1 = (minim + C[s[x] - 'a']+3)/4;
			valor += min(C[s[x] - 'a'], minim + change1 );
		}
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
  int change1 = (C[s[i-1] - 'a'] + minim+3)/4;
  int change2 = (C[t[j-1] - 'a'] + minim+3)/4;
  int change3 = (C[s[i-1] - 'a'] + C[t[j-1] - 'a']+3)/4;
  return res = min5(f(i, j - 1) + C[t[j-1] - 'a'], f(i - 1, j) + C[s[i-1] - 'a'], f(i, j-1) + minim + change2, f(i-1, j) + minim + change1, f(i-1, j-1) + change3);
}


int main() {
  while(cin >> n){
	C = VI(n);
	for(int i = 0; i < n; ++i){
		cin >> C[i];
		if(i == 0) minim = C[i];
		else if(C[i] < minim) minim = C[i];
	}
	cin >> s >> t;
    D = VVI(s.size() + 1, VI(t.size() + 1, -1));
    cout << f(s.size(), t.size()) << endl;
  }
}
