#include<iostream>
#include<vector>
using namespace std;

const int N = 10001;
const int M = 1e8+7;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
int n;
VVVI memo;

int f(int n, int k, int u){
	if(n == 1){
		if(u%7 == k) return 1;
		return 0;
	}
	int& q = memo[n][k][u];
	if(q != -1) return q%M;
	q = 0;
	
	int x = (((5*(k-u))%7) + 7) % 7;
	for(int y = 0; y < 10; ++y){
		if(y != u){
			q += f(n-1, x, y)%M;
		}
	}
	return q%M;
}




int main(){
	memo = VVVI(N, VVI(7, VI(10, -1)));
	while(cin >> n){
		int ans = 0;
		for(int ultim = 0; ultim < 10; ++ultim) ans += f(n, 0, ultim)%M;
		cout << ans%M << endl;
	}
}
