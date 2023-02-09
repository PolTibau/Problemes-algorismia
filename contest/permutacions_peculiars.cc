#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;
int n;
VB vist;
VI P;
const int superparell = 4;
const int supersenar = 5;




int main(){
	while(cin >> n){
		int compte = 1;
		for(int i = 1; i <= n; i += 2){
			if(i != supersenar){
				cout << i << ' ';
				++compte;
			}
		}
		cout << supersenar << ' ' << superparell << ' ';
		compte += 2;
		for(int j = 2; j <= n; j += 2){
			if(j!= superparell and compte == n)cout << j << endl;
			else if(j != superparell){
				++compte;
				cout << j << ' ';
			}
		}
	}
}
