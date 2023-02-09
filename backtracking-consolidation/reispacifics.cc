#include<iostream>
#include<vector>
using namespace std;

using taulell = vector<vector<bool> >;

taulell T;
int r, n;

void print(){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(T[i][j]) cout << 'K';
			else cout << '.';
		}
		cout << endl;
	}
	cout << "----------" << endl;
}

bool amenaça(int i, int j){
	if(i-1 >= 0 and j-1 >= 0 and T[i-1][j-1]) return true;
	else if(i-1 >= 0 and T[i-1][j]) return true;
	else if(j-1 >= 0 and T[i][j-1]) return true;
	else if(i-1 >= 0 and j+1 >= 0 and T[i-1][j+1]) return true;
	else if(i+1 < n and T[i][j+1]) return true;
	else if(i+1 < n and j+1 < n and T[i+1][j+1]) return true;
	else if(j-1 >= 0 and i+1 < n and T[i+1][j-1]) return true;
	else if(j+1 < n and T[i][j+1]) return true;
	else if(i+1 < n and T[i+1][j]) return true;
	return false;
}

void coloca(int x, int i, int j){
	if(x == r){
		print();
		return;
	}
	while(i < n){
		while(j < n){
			if(not T[i][j] and not amenaça(i, j)){
				T[i][j] = true;
				if(j+1 < n)coloca(x+1, i, j+1);
				else coloca(x+1, i+1, 0);
				T[i][j] = false;
			}
			++j;
		}
		++i;
		j = 0;
	}
	return;
}


int main(){
	cin >> n >> r;
	T = taulell(n, vector<bool>(n, false));
	coloca(0, 0, 0);
}
