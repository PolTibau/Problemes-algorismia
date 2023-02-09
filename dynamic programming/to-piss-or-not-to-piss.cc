#include<iostream>
#include<vector>
using namespace std;

//identificarem n amb el nombre d'urinaris
//identificarem m amb el percentatge desitjat
double n, m;
using VI = vector<int>;
using VVI = vector<VI>;
VVI W;

int walls(int n, int count){
	int& q = W[n][count];
	if(q != -1) return q;
	if(n == 1) return q = 1;
	for(int k = 1; k*(count+1) <= n; ++k){
		q = max(q, walls(k, 0) + walls(n-k, count-1));
	}
	return q;
}




int main(){
	W = VVI(501, VI(500, -1));
	W[1][0] = W[2][0] = 1;
	W[3][0] = W[4][0] = 2;
	for(int i = 5; i < 501; ++i){
		W[i][0] = W[(i+1)/2][0]+W[(i+2)/2][0]-1;
	}
	while(cin >> n >> m){
		int count = 0;
		while(100*walls(n, count) < n*m)++count;
		cout << count << endl;
	}
}
