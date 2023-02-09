#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;
int n, k;
VB C;
VI suma;
VI dip;

void print(){
	cout << "{";
	bool primer = true;
	for(int i = 0; i < n; ++i){
		if(C[i]){
			if(primer)primer = false;
			else cout << ", ";
			cout << i+1;
		}
	}
	cout << "}" << endl;
}


void revisa(int m, int q, int minim){
	if(q >= k and q-minim < k)return print();
	if(q >= k or m == n or q+suma[m] < k)return;
	C[m] = true;
	revisa(m+1, q+dip[m], min(minim, dip[m]));
	C[m] = false;
	revisa(m+1, q, minim);
}



int main(){
	while(cin >> k >> n){
		dip = VI(n);
		suma = VI(n, 0);
		C = VB(n, false);
		for(int i = 0; i < n; ++i)cin >> dip[i];
		suma[n-1] = dip[n-1];
		for(int i = n-2; i >= 0; --i){
			suma[i] = dip[i]+suma[i+1];
		}
		revisa(0, 0, 100000000);
		cout << "----------" << endl;
	}
}
