#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<string, int>& a, pair<string, int>& b){
	if(a.second != b.second) return a.second > b.second;
	else return a.first < b.first;
}

int main(){
	string s, jugador, j1, j2;
	map<string, int> Joc, Ranking;
	while(cin >> s){
		if(s == "LOGIN"){
			cin >> jugador;
			if(Joc.count(jugador) == 0) Joc.insert({jugador, 1200});
			if(Ranking.count(jugador) == 0) Ranking.insert({jugador, 1200});
		}
		else if(s == "LOGOUT"){
			cin >> jugador;
			if(Joc.count(jugador) == 1){
				Joc.erase(jugador);
			}
		}
		else if(s == "PLAY"){
			cin >> j1 >> j2;
			if(Joc.count(j1) == 0 or Joc.count(j2) == 0) cout << "jugador(s) no connectat(s)" << endl;
			else{
				Ranking[j1] += 10;
				Joc[j1] += 10;
				if(Ranking[j2] >= 1210) Ranking[j2] -= 10;
				if(Joc[j2] >= 1210) Joc[j2] -= 10;
			}
		}
		else{
			cin >> jugador;
			cout << jugador << ' ' << Ranking[jugador] << endl;
		}
	}
	cout << endl << "RANKING" << endl;
	vector<pair<string, int> > R;
	for(auto it: Ranking)R.push_back(it);
	sort(R.begin(), R.end(), comp);
	for(auto it: R) cout << it.first << ' ' << it.second << endl;
}
