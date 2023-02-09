#include<iostream>
#include<vector>
using namespace std;

using triangle_de_pascal = vector<vector<int> >;

int n, k;
triangle_de_pascal T;

int construeix(int i, int j, triangle_de_pascal& T){
	if (i == 0 or j == 0 or j == i or (j == 1 and i == 1)) return 1;
	else{
		if(T[i][j] == 1){
			T[i-1][j-1] = construeix(i-1, j-1, T);
			T[i-1][j] = construeix(i-1, j, T);
			T[i][j] = T[i-1][j-1] + T[i-1][j];
			return T[i][j];
		}
		else return T[i][j];
	}
}

int main(){
	T = triangle_de_pascal(31, vector<int>(31, 1));
	while(cin >> n >> k){
		if(k == n or k == 0) cout << 1 << endl;
		else{
			cout << construeix(n, k, T) << endl;
		} 
	}
}
