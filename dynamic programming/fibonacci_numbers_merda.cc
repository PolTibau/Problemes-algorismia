#include<iostream>
#include<vector>
using namespace std;

int n, m;

int main(){
	while(cin >> n >> m){
		int a = 0;
		int b = 1;
		int t = 0;
		while(n--){
			int t = a+b;
			a = b;
			b = t;
			if(t >= m) t-= m;
		}
		cout << t << endl;
	}
}
