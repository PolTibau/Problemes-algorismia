#include<iostream>
#include<vector>
using namespace std;

int n, k, p;
using VI = vector<double>;
using VVI = vector<VI>;
VVI M;
VI P;


double probabilitat(int n, int k){
	if(n == 0)return 1;
	if(k == 0)return (1-P[n])*probabilitat(n-1, k);
	if(n == k)return (P[n])*probabilitat(n-1, k-1);
	double& q = M[n][k];
	if(q != -1)return q;
	return q = P[n]*probabilitat(n-1, k-1) + (1-P[n])*probabilitat(n-1, k);
}



int main(){
	cout.setf(ios::fixed);
	cout.precision(4);
	while(cin >> n >> k){
		P = VI(n+1, 0);
		M = VVI(n+1, VI(k+1, -1));
		for(int i = 1; i <= n; ++i)cin >> P[i];
		cout << probabilitat(n, k) << endl;
	}
}
