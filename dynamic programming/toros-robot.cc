#include<iostream>
#include<vector>
using namespace std;

using visio = vector<vector<int> >;
using marca = vector<int>;
visio  M, P;
marca K;

int w, h, c;

int sum(int i, int j){
	int sum = 0;
	if(i == 0 and j == 0){
		for(int x = 0; x < c; ++x){
			for(int y = 0; y < c; ++y){
				sum += M[i+x][j+y];
			}
		}
	}
	else if(j == 0){
		sum = P[i-1][j];
		for(int x = 0; x < c; ++x){
			sum -= M[i-1][x];
			sum += M[i+c-1][x];
		}
	}
	else{
		sum = P[i][j-1];
		for(int x = 0; x < c; ++x){
			sum -= M[i+x][j-1];
			sum += M[i+x][j+c-1];
		}

	}
	return sum;
}


int main(){
	K = marca(2, 0);
	int compte = 0;
	cin >> w >> h >> c;
	P = visio(h-c+1, vector<int>(w-c+1));
	M = visio(h, vector<int>(w));
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			cin >> M[i][j];
		}
	}
	for(int i = 0; i < h-c+1; ++i){
		for(int j = 0; j < w-c+1; ++j){
			P[i][j] = sum(i, j);
			if(P[i][j] > compte){
				compte = P[i][j];
				K[0] = i;
				K[1] = j;
			}
		}
	}
	cout << K[0] << ' ' << K[1] << endl;
}
