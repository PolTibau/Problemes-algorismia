#include<iostream>
#include<vector>
#include<string>
using namespace std;

using conjunt = vector<string>;
using contador = vector<bool>;

conjunt C;
contador A;
int n;
int i;


void print(){
  cout << '{';
  int compte = 0;
  for(int k = 0; k < n; ++k){
	  if(A[k] == true){
		compte++;
		cout << C[k];
		if(compte < i) cout << ", ";  
	}
  }
  cout << '}' << endl;
}



void f(int m, int cardinal){
  if(m == n) return print();
  if(m-cardinal < n-i){ 
	A[m] = false;
	f(m+1, cardinal);
  }
  if(cardinal < i){
	A[m] = true;
	f(m+1, cardinal+1);
  }
}


int main(){
  cin >> i >> n;
  C = conjunt(n);
  for(int k = 0; k < n; ++k) cin >> C[k];
  A = contador(n);
  if(i > 0){
	f(0,0);
  }
  else{
	 cout << "{}" << endl;
  }
}
