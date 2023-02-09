#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct pos{
	int x;
	int y;
	friend bool operator< (const pos& a, const pos& b){
		return a.x < b.x;
	}
	pos(int i1, int i2){
	x = i1;
	y = i2;
	}
};
using VC = vector<char>;
using VVC = vector<VC>;
using VB = vector<bool>;
using VVB = vector<VB>;
using R = pair<int, pos>;
using P = pair<int, R>;
VVC G;
int persones, passos, n, m;





void troba_el_telecos(){
	priority_queue<P> Q;
	VVB vist(n, VB(m, false));
	if(G[0][0] == '.') Q.push(P(0, R(0,pos(0,0))));
	else if(G[0][0] == 'T'){
		passos = 0;
		persones = 0;
		return;
	}
	else if(G[0][0] == 'P')Q.push(P(0, R(1,pos(0,0))));
	while(not Q.empty()){
		P p = Q.top();
		Q.pop();
		int pas = -p.first;
		int pers = p.second.first;
		pos act = p.second.second;
		if(G[act.x][act.y] == 'T'){
			passos = pas;
			persones = pers;
			return;
		}
		if(act.x+1 < n and not vist[act.x+1][act.y]){
			vist[act.x+1][act.y] = true;
			if(G[act.x+1][act.y] == 'P')Q.push(P(-pas-1, R(pers+1, pos(act.x+1, act.y))));
			else if(G[act.x+1][act.y] != '#') Q.push(P(-pas-1, R(pers, pos(act.x+1, act.y))));
		}
		if(act.x-1 >= 0 and not vist[act.x-1][act.y]){
			vist[act.x-1][act.y] = true;
			if(G[act.x-1][act.y] == 'P')Q.push(P(-pas-1, R(pers+1, pos(act.x-1, act.y))));
			else if(G[act.x-1][act.y] != '#') Q.push(P(-pas-1, R(pers, pos(act.x-1, act.y))));
		}
		if(act.y+1 < m and not vist[act.x][act.y+1]){
			vist[act.x][act.y+1] = true;
			if(G[act.x][act.y+1] == 'P')Q.push(P(-pas-1, R(pers+1, pos(act.x, act.y+1))));
			else if(G[act.x][act.y+1] != '#') Q.push(P(-pas-1, R(pers, pos(act.x, act.y+1))));
		}
		if(act.y-1 >= 0 and not vist[act.x][act.y-1]){
			vist[act.x][act.y-1] = true;
			if(G[act.x][act.y-1] == 'P')Q.push(P(-pas-1, R(pers+1, pos(act.x, act.y-1))));
			else if(G[act.x][act.y-1] != '#') Q.push(P(-pas-1, R(pers, pos(act.x, act.y-1))));
		}
	}
}


int main(){
	while(cin >> n >> m){
		G = VVC(n, VC(m));
		bool hi_es = false;
		persones = 0;
		passos = -1;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> G[i][j];
				if(G[i][j] == 'T')hi_es = true;
			}
		}
		if(not hi_es)cout << "El telecos ha fugit." << endl;
		else{
			troba_el_telecos();
			if(passos == -1) cout << "El telecos esta amagat." << endl;
			else cout << passos << ' ' << persones << endl;
		}
	}
}
