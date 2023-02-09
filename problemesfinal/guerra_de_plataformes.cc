#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

int n, m;
using P = pair<int, int>;
using S = set<P>;
using VS = vector<S>;
using VB = vector<bool>;
using VVB = vector<VB>;
using CC = map<P, int>;
CC memo;
VVB T, M;


void DFS(int i, int j, int comp, S& plat){
	if(not M[i][j])return;
	M[i][j] = false;
	memo[P(i, j)] = comp;
	plat.insert(P(i, j));
	if(i+1 < n and M[i+1][j])DFS(i+1, j, comp, plat);
	if(i-1 >= 0 and M[i-1][j])DFS(i-1, j, comp, plat);
	if(j+1 < m and M[i][j+1])DFS(i, j+1, comp, plat);
	if(j-1 >= 0 and M[i][j-1])DFS(i, j-1, comp, plat);
}


int main(){
	cin >> n >> m;
	T = VVB(n, VB(m));
	M = VVB(n, VB(m));
	char c;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> c;
			if(c == 'X'){
				M[i][j] = true;
				T[i][j] = true;
				memo[P(i,j)] = -2;
			}
			else{
				M[i][j] = false;
				T[i][j] = false;
				memo[P(i,j)] = -1;
			}
		}
	}
	int comp = 0;
	VS aguanta(0);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(T[i][j] and memo[P(i, j)] == -2){
				S plat;
				memo[P(i, j)] = comp;
				plat.insert(P(i,j));
				DFS(i, j, comp, plat);
				aguanta.push_back(plat);
				comp++;
			}
		}
	}
	S no_tocat;
	VS tocat(aguanta.size());
	int ai, aj;
	int guanya = 0;
	bool victoria = false;
	bool fi = false;
	while(not fi and cin >> ai >> aj){
		ai--;
		aj--;
		if(T[ai][aj]){
			int ind = memo[P(ai,aj)];
			if(tocat[ind].count(P(ai,aj))){
				fi = true;
				cout << ai+1 << ' ' << aj+1 << ": " << "REPEATED" << endl;
			}
			else{
				tocat[ind].insert(P(ai,aj));
				if(aguanta[ind].size() == tocat[ind].size()){
					cout << ai+1 << ' ' << aj+1 << ": " << "hit and sunk" << endl;
					guanya++;
					if(guanya == comp){
						victoria = true;
						fi = true;
					}
				}
				else{
					cout << ai+1 << ' ' << aj+1 << ": " << "hit" << endl;
					tocat[ind].insert(P(ai,aj));
				}
			}
		}
		else{
			if(not no_tocat.count(P(ai,aj))){
				no_tocat.insert(P(ai,aj));
				cout << ai+1 << ' ' << aj+1 << ": " << "miss" << endl;
			}
			else{
				fi = true;
				cout << ai+1 << ' ' << aj+1 << ": " << "REPEATED" << endl;
			}
		}
	}
	if(victoria)cout << "VICTORY" << endl;
	else if(not fi)cout << "UNFINISHED" << endl;
}
