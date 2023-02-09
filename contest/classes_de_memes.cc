#include<iostream>
#include<vector>
using namespace std;

using P = pair<int, int>;
using VP = vector<P>;
using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
VP V;
VVI memo;
VB vist;
int n, t;
//V guarda al primer lloc el temps consumit i al segon lloc el coneixement;

//dona el maxim knowledge amb i videos i d segons;
int memes(int d, int i){
	if(i == -1)return d;
	if(d == 0)return 0;
	int& q = memo[d][i];
	if(q != -1)return q;
	if(d-V[i].first >= 0)return q = max(V[i].second + memes(d-V[i].first, i-1), memes(d, i-1));
	return q = memes(d, i-1);
}

int main(){
	while(cin >> t >> n){
		V = VP(n);
		memo = VVI(t+1, VI(n, -1));
		for(int i = 0; i < n; ++i){
			cin >> V[i].first;
			cin >> V[i].second;
		}
		cout << memes(t, n-1) << endl;
	}
}
