#include<iostream>
#include<vector>
using namespace std;

using peces = vector<char>;
using toys = vector<vector<char> >;
using control = vector<bool>;

int n;
int i = 1;
peces cossos, cames, S;
control C2, C3;

void print(){
	int p = 0;
	for(int i = 0; i < 2*n; i+=2){
		cout << char('A' + p);
		cout << S[i] << S[i+1];
		if(i < 2*n-2) cout << '-';
		++p;
	}
	cout << endl;
}



void f(int m){
	if(m == 2*n) return print();
	if(m%2 == 0){
		for(int i = 0; i < n; ++i){
			if(not C2[i]){
				C2[i] = true;
				S[m] = cossos[i];
				f(m+1);
				C2[i] = false;
			}
		}
	}
	else{
		for(int j = 0; j < n; ++j){
			if(not C3[j]){
				C3[j] = true;
				S[m] = cames[j];
				f(m+1);
				C3[j] = false;
			}
		}
	}
}




int main(){
	while(cin >> n and n != 0){
		cout << "Case " << i << endl;
		cossos = cames = peces(n);
		for(int i = 0; i < n; ++i){
			cames[i] = char('a' + i);
			cossos[i] = char('0' + i);
		}
		S = peces(2*n);
		C2 = C3 = control(n, false);
		f(0);
		++i;
	}
}
