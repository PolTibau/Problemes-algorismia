#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
string mot;
VI dp;

int subsequence(int i){
	if(dp[i] != -1) return dp[i];
	if(i == 0){
		dp[i] = 0;
		return dp[i];
	}
	dp[i] = 0;
	for(int x = 0; x < i; ++x){
		if(mot[i] > mot[x]){
			dp[i] += 1 + subsequence(x);
		}
	}
	return dp[i];
}


int main(){
	while(cin >> mot){
		dp = VI(mot.size(), -1);
		int total = 0;
		for(int i = 1; i < mot.size(); ++i)total += subsequence(i);
		cout << total << endl;
	}
}
