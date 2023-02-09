#include<iostream>
#include<queue>
#include<vector>
using namespace std;

using Pos = pair<int, int>;
using tup = pair<int, Pos>;
using VB = vector<bool>;
using VVB = vector<VB>;
VVB vist;
int n;

int busca_en_pifa(Pos inici, Pos fin){
    queue<tup> Q;
    Q.push(tup(0, inici));
    while(not Q.empty()){
        tup t = Q.front();
        Q.pop();
        int pas = t.first;
        Pos act = t.second;
				if(act == fin) return pas;
				if(act.first+1 < n and not vist[act.first+1][act.second]){
						Q.push(tup(pas+1, Pos(act.first+1, act.second)));
						vist[act.first+1][act.second] = true;
				}
				if(act.first-1 >= 0 and not vist[act.first-1][act.second]){
						Q.push(tup(pas+1, Pos(act.first-1, act.second)));
						vist[act.first-1][act.second] = true;
				}
				if(act.second+1 < n  and not vist[act.first][act.second+1]){
						Q.push(tup(pas+1, Pos(act.first, act.second+1)));
						vist[act.first][act.second+1] = true;
				}
				if(act.second-1 >= 0 and not vist[act.first][act.second-1]){
						Q.push(tup(pas+1, Pos(act.first, act.second-1)));
						vist[act.first][act.second-1] = true;
				}
    }
    return -1;
}
            


int main(){
    while(cin >> n){
        char c;
				vist = VVB(n, VB(n, false));
        Pos inici;
				Pos fin;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
							cin >> c;
							if(c == 'P'){
									inici.first = i;
									inici.second = j;
							}
							else if(c == 'B'){
								vist[i][j] = true;
							}
							else if(c == 'C'){
								fin.first = i;
								fin.second = j;
							}
            }
        }
        cout << busca_en_pifa(inici, fin) <<endl;
    }
}
        
        
        
