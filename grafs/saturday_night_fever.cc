#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, s, h, m, v;
using VB = vector<bool>;
using VVB = vector<VB>;
using VI = vector<int>;
using VVI = vector<VI>;
using P = pair<pair<int, int>, int>;
VVB vist;
VI V;
VVI G;

int arriba(queue<P>& Q){
	vist = VVB(n+1, VB(v, false));
	while(not Q.empty()){
		int act = Q.front().first.first;
		int minut = Q.front().first.second;
		int wait = Q.front().second;
		Q.pop();
		if(not vist[act][minut%v]){
			vist[act][minut%v] = true;
			if(act != h){
				if(wait < v and V[(minut+1)%v] != act)Q.push({{act, minut+1}, wait+1});
				for(int u: G[act]){
					if(V[(minut+1)%v] != u and not(V[minut%v] == u and V[(minut+1)%v] == act))Q.push({{u,minut+1}, 0});
				}
			}
			else return minut;
		}
	}
	return -1;
}

int main(){
	while(cin >> n >> s >> h){
		G = VVI(n+1);
		cin >> m;
		int a, b;
		for(int i = 0; i < m; ++i){
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		cin >> v;
		V = VI(v);
		int c;
		for(int i = 0; i < v; ++i){
			cin >> c;
			V[i] = c;
		}
		queue<P> Q; //guardem(posicio, minut, temps d'espera)
		Q.push({{s,0}, 0});
		int t = arriba(Q);
		if(t == -1)cout << "Tu es foutu, Evariste!" << endl;
		else if(t == 1) cout << "C'est une minute, Evariste!" << endl;
		else cout << "Ce sont " << t << " minutes, Evariste!" << endl;
	}
}
