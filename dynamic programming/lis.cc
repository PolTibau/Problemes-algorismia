#include<iostream>
#include<vector>
using namespace std;


int n;
using VI = vector<int>;
VI S;

int subsequence(int i){
	int compte = 0
	int ultim = S[i]
	for(int x = i; x < S.size(); ++x){
		if(S[x] > ultim){
			++compte;
			ultim = S[x];
		}
	}
	return compte;
}





int main(){
	while(cin >> n){
		S = VI(n);
		int maxim = 0
		for(int i = 0; i < n; ++i) cin >> S[i];
		for(int i = 0; i < n; ++i){
			int t = subsequence(i)
			if(maxim < t) maxim = t;
		}
		cout << maxim << endl;
	}
}
