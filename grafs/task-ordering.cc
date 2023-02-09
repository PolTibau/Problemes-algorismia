#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int main(){
    int n, m;
    while(cin >> n){
        string s;
		map<string, int> h;
        map<string, vector<string> > g;
        for(int i = 0; i < n; ++i){
            cin >> s;
            h[s] = 0;
        }
        cin >> m;
        for(int i = 0; i < m; ++i){
            string x, y;
            cin >> x >> y;
            g[x].push_back(y);
            h[y]++;
        }
        set<string> C;
        for(auto it = h.begin(); it != h.end(); ++it){
            if(it->second == 0) C.insert(it->first);
        }
		queue<string> Q;
        while(not C.empty()){
            string x = *C.begin();
			Q.push(x);
			C.erase(*C.begin());
			for(string i : g[x]){
                auto it = h.find(i);
                if(--(it->second) == 0)C.insert(it->first);
            }
        }
        if(Q.size() < n) cout << "NO VALID ORDERING";
        else{
			while(not Q.empty()){
				cout << Q.front();
				Q.pop();
			}
		}
		cout << endl;
    }
}
