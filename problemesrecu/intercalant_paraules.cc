#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e8+7;
string s, t;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
VVVI memo;

int combina(int x, int y, int u){
	int& q = memo[u][x][y];
	if(q != -1) return q;
	q = 0;
	char ult;
	if(u)ult = s[x];
	else ult = t[y];
	int nx = x;
	int ny = y;
	if(u) nx++;
	else ny++;
	if(nx < s.size() and s[nx] != ult)q+=(combina(nx,ny, 1)%MOD);
	if(ny < t.size() and t[ny] != ult)q+=(combina(nx,ny, 0)%MOD);
	return q;
}


int main(){
	while(cin >> s >> t){
		memo = VVVI(2, VVI(s.size()+1, VI(t.size()+1, -1)));
		memo[0][s.size()][t.size()-1] = memo[1][s.size()-1][t.size()] = memo[1][s.size()][t.size()-1] = memo[0][s.size()-1][t.size()] = 1;
		cout << (combina(0,0,0) + combina(0,0, 1))%MOD << endl;
	}
}
