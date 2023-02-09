#include<iostream>
#include<set>
#include<queue>
using namespace std;


int main(){
	int n;
	while(cin >> n){
		priority_queue<int> B;
		priority_queue<int> joies;
		int j;
		long long suma = 0;
		for(int i = 1; i <= n; ++i){
			cin >> j;
			B.push(j);
			int m = (2*i)/3 - joies.size();
			for(int k = m; k > 0 and not B.empty(); --k){
				int t = -B.top();
				B.pop();
				joies.push(t);
				suma += -t;
			}
			while(not joies.empty() and not B.empty() and B.top() > -joies.top()){
				int entra = B.top();
				int surt = -joies.top();
				suma += entra - surt;
				B.pop();
				joies.pop();
				B.push(surt);
				joies.push(-entra);
			}
			cout << suma << endl;
		}
		cout << "----------" << endl;
	}
}
