#include<iostream>
#include<vector>
#include<map>
using namespace std;


using VI = vector<int>;

int main(){
	int n, m;
	map<int, int> P;
	cin >> n >> m;
	int x;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> x;
			P[x] = i;
		}
	}
	VI F(n, m);
	int num;
	while(cin >> num and P.size() != 0){
		int line;
		if(P.count(num)){
			line = P[num];
			P.erase(num);
			F[line]--;
			if(F[line] == 0) cout << num << " linia " << line+1 << endl;
		}
		if(P.size() == 0)cout << num << ' ' << "bingo" << endl;
	}
}
