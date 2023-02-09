#include<iostream>
#include<vector>
using namespace std;

using VI = vector<char>;
using VVI = vector<VI>;
VVI T;

int main(){
	int n;
	cin >> n;
	for(int k = 0; k < n; ++k){
		T = VVI(3, VI(3));
		int f = 0;
		int o = 0;
		int x = 0;
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				cin >> T[i][j];
				if(T[i][j] == 'O' or T[i][j] == 'X')++f;
				if(T[i][j] == 'O')o++;
				else if(T[i][j] == 'X')x++;
			}
		}
		if(o == 0)cout << 'X' << endl;
		else if(f%2 == 0)cout << 'X' << endl;
		else cout << 'O' << endl;
	}
}
