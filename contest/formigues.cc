#include<iostream>
#include<vector>
using namespace std;

int compte;


int main(){
	int a, b;
	while(cin >> a >> b){
		int compte = 0;
		while(a > 0 and b > 0){
			compte += (a-1)+(b-1)+1;
			a--;
			b--;
		}
		cout << compte << endl;
	}
}
