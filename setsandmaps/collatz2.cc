#include<iostream>
#include<map>
using namespace std;

int main(){
	long long n;
	int x, y;
	while(cin >> x >> y >> n){
		map<long long, int> S;
		S[n] = 0;
		int i = 1;
		bool trobat = false;
		while(not trobat){
			if(n%2 == 0){
				n /= 2;
				n += x;
			}
			else{
				n *= 3;
				n += y;
			}
			if(not S.count(n) and n <= 1e8)S[n] = i;
			else trobat = true;
			++i;
		}
		if(n > 1e8)cout << n << endl;
		else{
			int ind = S[n];
			cout << S.size() - ind << endl;
		}
	}
}
