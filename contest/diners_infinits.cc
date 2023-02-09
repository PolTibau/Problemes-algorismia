#include<iostream>
#include<vector>
using namespace std;

struct prod{
	int p;
	int a;
	int b;
};
int n,d,m;
using VI = vector<int>;
using VVI = vector<VI>;
using P = pair<int, int>;
using VP = vector<P>;
VP V;
VVI memo;

//retorna el maxim benefici que es poden comprar amb d euros
int compra(int d, int m){
	if(d == 0 or m == 0)return 0;
	int& q = memo[d][m];
	if(q != -1)return q;
	for(int i = 0; i < n; ++i){
		if(d-V[i].first >= 0)q = max(q, V[i].second + compra(d-V[i].first, m-1));
	}
	return q;
}





int main(){
	while(cin >> n >> d >> m){
		V = VP(n);
		memo = VVI(d+1, VI(m+1, -1));
		for(int i = 0; i < n; ++i){
			prod x;
			cin >> x.p >> x.a >> x.b;
			V[i].first = x.b;
			V[i].second = x.a*x.p-x.b;
		}
		cout << compra(d, m) << endl;
	}
}
