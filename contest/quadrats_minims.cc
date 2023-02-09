#include<iostream>
#include<vector>
using namespace std;


int n, a, b;
bool entren(int i, int j, int x, int n){
	if(i > x)return false;
	if(n == 0)return true;
	if(j+b > x) return entren(i+a, 0, x, n-1);
	else return entren(i, j+b, x, n-1);
}


int main(){
	while(cin >> n >> a >> b){
		long long x = 1;
		while(not entren(0,0,x,n)){
			x++;
		}
		cout << x << endl;
	}
}
