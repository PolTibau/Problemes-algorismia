#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;

int main(){
	int n, k;
	while(cin >> n >> k){
		int vent = 0;
		int energia = k;
		int consum;
		for(int i = 0; i < n; ++i){
			cin >> consum;
			if(energia-consum < 0){
				vent++;
				energia = k;
			}
			energia -= consum;
		}
		cout << vent << endl;
	}
}
