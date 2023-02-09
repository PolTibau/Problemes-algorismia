#include<iostream>
#include<vector>
using namespace std;

int a, b, n;
int ordenacions = 0;

using objectes = vector<vector<int> >;
using maleta = vector<vector<bool> >;
using control = vector<bool>;

maleta M;
control C;
objectes O;

void marca(int i, int j, int fin1, int fin2){
	for(int n = 0; n < fin1; ++n){
		for(int m = 0; m < fin2; ++m){
			M[i+n][j+m] = true;
		}
	}
}


void desmarca(int i, int j, int fin1, int fin2){
	for(int n = 0; n < fin1; ++n){
		for(int m = 0; m < fin2; ++m){
			M[i+n][j+m] = false;
		}
	}
}



bool ocupat(int i, int j, int fin2){
	for(int m = 0; m < fin2; ++m){
		if(M[i][j+m]) return true;
	}
	return false;
}

int organitza(int i, int j){
	if(i == a) return 1;
	if(j == b) return organitza(i+1, 0);
	if(M[i][j]) return organitza(i, j+1);
	int compte = 0;
	for(int t = 0; t < n; ++t){
		if(not C[t] and O[t][0]+i-1 < a and O[t][1]+j-1 < b and not ocupat(i, j, O[t][1])){
			marca(i, j, O[t][0], O[t][1]); 
			C[t] = true;
			compte += organitza(i, j+1);
			C[t] = false;
			desmarca(i, j, O[t][0],O[t][1]);
		}
	}
	return compte;
}





int main(){
	int s = 1;
	while(cin >> a >> b >> n){
		C = control(n, false);
		M = maleta(a, vector<bool>(b, false));
		O = objectes(n, vector<int>(2));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < 2; ++j){
				cin >> O[i][j];
			}
		}
		cout << "#" << s << ": " << organitza(0, 0) << endl;
		++s;
	}
}
