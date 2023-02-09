#include<iostream>
#include<vector>
using namespace std;

using ll = long long;
using VI = vector<ll>;
using VVI = vector<VI>;
VVI memo;
VI num;
int n;


//returna el nombre maxim que podem generar fins la posicio i tenint l'actual factor k termes
ll maxproduct(int i, int k, ll acum){
	if(i == n and k != 0)return acum;
	if(i == n and k == 0)return 0;
	ll& q = memo[i][k];
	if(q != -1)return q;
	
	if(acum == 0)acum = num[i];
	else acum *= num[i];
	
	if(k == 2)return q = acum + maxproduct(i+1, 0, 0);
	return q = max(maxproduct(i+1, k+1, acum), acum + maxproduct(i+1, 0, 0));
}






int main(){
	while(cin >> n){
		num = VI(n);
		for(int i = 0; i < n; ++i)cin >> num[i];
		memo = VVI(n, VI(3, -1));
		ll t = maxproduct(0, 0, 0);
		cout << t << endl;
	}
}
