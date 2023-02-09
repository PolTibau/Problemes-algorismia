#include<iostream>
#include<vector>
using namespace std;

using VI = vector<vector<int> >;
VI compte;
string a, b;
int maxim;
bool trobat;

bool es_mes_petit(int pos, int j){
	for(int x = 0; x < maxim; ++x){
		if(b[pos-maxim+x] < b[j-maxim+x]) return false; 
		else if(b[pos-maxim+x] > b[j-maxim+x]) return true;
	}
	return true;
}


int main(){
	while(cin >> a >> b){
		trobat = false;
		compte = VI(a.size()+1, vector<int>(b.size()+1, 0));
		maxim = 0;
		for(int i = 1; i < a.size()+1; ++i){
			for(int j = 1; j < b.size()+1; ++j){
				if(b[j-1] == a[i-1]){
					compte[i][j] = compte[i-1][j-1] + 1;
					if(compte[i][j] > maxim){
						maxim = compte[i][j];
					}
				}
			}
		}
		int pos;
		if(maxim == 0) cout << endl;
		else{
			for(int i = 1; i < a.size()+1; ++i){
				for(int j = 1; j < b.size()+1; ++j){
					if(compte[i][j] == maxim){
						if(not trobat){
							pos = j;
							trobat = true;
						}
						else if(es_mes_petit(pos, j)) pos = j;
					}
				}
			}
			for(int x = 0; x < maxim; ++x){
				cout << b[pos-maxim+x];
			}
			cout << endl;
		}
	}
}
