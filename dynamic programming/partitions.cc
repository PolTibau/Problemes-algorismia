#include<iostream>
#include<vector>
using namespace std;


using VI = vector<int>;
int n;
VI P;
const int N = 3*1e4+1;


int nice_partitions(int n){
	if(n >= 2 and n <= 5) return 1;
	int& q = P[n];
	if(q != -1) return q;
	q = 0;
	return q;
}


int main(){
	P = VI(N, -1);
	P[2] = P[3] = P[4] = P[5] = 1;
	while(cin >> n){
		if(n < 4) cout << 0 << endl;
		else cout << nice_partitions(n) << endl;
		for(int i = 0; i < n; ++i) cout << P[i] << ' ';
		cout << endl;
	}
}
