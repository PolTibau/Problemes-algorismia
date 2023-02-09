#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;


int main(){
	queue<string> Q;
	vector<queue<string> > cua;
	cua = vector<queue<string> >(26);
	string s;
	while(cin >> s) Q.push(s);
	if(Q.size() == 0) cout << endl;
	else{
		int n = s.size();
		for(int i = n-1; i >= 0; --i){
			while(not Q.empty()){
				string q = Q.front();
				cua[q[i] - 'a'].push(q);
				Q.pop();
			}
			for(int j = 0; j < 26; ++j){
				while(not cua[j].empty()){
					string t = cua[j].front();
					Q.push(t);
					cua[j].pop();
				}
			}
		}
		while(not Q.empty()){
			if(Q.size() == 1) cout << Q.front() << endl;
			else cout << Q.front() << ' ';
			Q.pop();
		}
	}
}
