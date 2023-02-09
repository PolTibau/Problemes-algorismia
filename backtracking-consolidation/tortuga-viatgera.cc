#include<iostream>
#include<vector>
using namespace std;

using recorregut = vector<char>;
using rajoles = vector<recorregut >;
using coordenades = vector<int>;
using control = vector<vector<bool> >;

int n, m;
recorregut cami;
coordenades I, F;
rajoles R;
control C;

void print(){
	for(int i = 0; i < cami.size(); ++i){
		cout << cami[i];
	}
	cout << endl;
}



void viatge(int x1, int x2){
	if(x1 == F[0] and x2 == F[1]){
		print();
		return;
	}
	if((x1+1 >= n or C[x1+1][x2]) and (x1-1 < 0 or C[x1-1][x2]) and (x2+1 >= m or C[x1][x2+1]) and (x2-1 < 0 or C[x1][x2-1])) return;
	if(x1+1 < n and not C[x1+1][x2]){
		C[x1+1][x2] = true;
		cami.push_back(R[x1+1][x2]);
		viatge(x1+1, x2);
		cami.pop_back();
		C[x1+1][x2] = false;
	}
	if(x1-1 >= 0 and not C[x1-1][x2]){
		C[x1-1][x2] = true;
		cami.push_back(R[x1-1][x2]);
		viatge(x1-1, x2);
		cami.pop_back();
		C[x1-1][x2] = false;
	}
	if(x2+1 < m and not C[x1][x2+1]){
		C[x1][x2+1] = true;
		cami.push_back(R[x1][x2+1]);
		viatge(x1, x2+1);
		cami.pop_back();
		C[x1][x2+1] = false;
	}
	if(x2-1 >= 0 and not C[x1][x2-1]){
		C[x1][x2-1] = true;
		cami.push_back(R[x1][x2-1]);
		viatge(x1, x2-1);
		cami.pop_back();
		C[x1][x2-1] = false;
	}
}


int main(){
	cin >> n >> m;
	cami = recorregut(0);
	R = rajoles(n, recorregut(m));
	I = F = coordenades(2);
	C = control(n, vector<bool>(m, false));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> R[i][j];
		}
	}
	for(int i = 0; i < 2; ++i){
		cin >> I[i];
	}
	for(int i = 0; i < 2; ++i){
		cin >> F[i];
	}
	C[I[0]][I[1]] = true;
	cami.push_back(R[I[0]][I[1]]);
	viatge(I[0], I[1]);
}
