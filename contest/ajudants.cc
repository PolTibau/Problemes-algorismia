#include<iostream>
using namespace std;


int main(){
	cout.setf(ios::fixed);
	cout.precision(4);
	int n;
	while(cin >> n){
		double x;
		double prod = 1;
		for(int i = 0; i < n; ++i){
			cin >> x;
			prod *= (1-x);
		}
		cout << 1-prod << endl;
	}
}
