#include<iostream>
using namespace std;
#include<vector>

int s, n;
vector<int> x, sol;

void gen(int i){
	if(i == n){
		int sum = 0;
		for(int j = 0; j < n; ++j){
			if(sol[j]){
				sum += x[j];
			}
		}
		if(s == sum){
			cout << "{";
			bool primer = true;
			for(int j = 0; j < n; ++j){
				if(sol[j]){
					if(primer) primer = false;
					cout << ",";
					cout << x[j];
				}
			}
			cout << "}" << endl;
		}
	}
	else{
		sol[i] = 0;
		gen(i+1);
		sol[i] = 1;
		gen(i+1);
	}
}

int main(){
	cin >> s >> n;
	x = vector<int>(n);
	for(int& xi : x){
		cin >> xi;
	}
	sol = vector<int>(n);
	gen(0);´
}
