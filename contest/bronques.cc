#include<iostream>
#include<map>
#include<vector>
using namespace std;


int main(){
	int n;
	while(cin >> n){
		string s, persona;
		map<string, pair<int, int>> M;
		map<string, string> R;
		map<pair<string, string>, pair<bool,bool>> W;
		for(int i = 0; i < n; ++i){
			cin >> persona;
			cin >> s;
			R.insert({s, persona});
			M.insert({s, make_pair(0,0)});
		}
		int vots;
		cin >> vots;
		string p, d, prop;
		for(int l = 0; l < vots; ++l){
			cin >> p >> d >> prop;
			if(W[make_pair(prop, p)].first == false){
				W[make_pair(prop, p)].first = true;
				if(d == "SI"){
					M[prop].first += 1;
					W[make_pair(prop, p)].second = true;
				}
				if(d == "NO"){
					M[prop].second += 1;
					W[make_pair(prop, p)].second = false;
				}
			}
			else{
				if(d == "SI" and W[make_pair(prop, p)].second == false){
					M[prop].first += 1;
					M[prop].second -= 1;
					W[make_pair(prop, p)].second = true;
				}
				else if(d == "NO" and W[make_pair(prop, p)].second == true){
					M[prop].first -= 1;
					M[prop].second += 1;
					W[make_pair(prop, p)].second = false;
				}
			}
		}
		for(auto it = M.begin(); it != M.end(); ++it){
			if(it->second.first > it->second.second){
				cout << it->first << ", de " << R[it->first] << ", que ha guanyat " << it->second.first << '-' << it->second.second << endl;
			}
		}
		cout << "----------" << endl;
	}
}
