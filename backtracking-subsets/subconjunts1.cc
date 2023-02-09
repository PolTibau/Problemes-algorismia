#include<iostream>
#include<vector>
using namespace std;

using conjunt = vector<string>;

int n;
conjunt C;

void print(conjunt A){
  cout << '{';
  for(int i = 0; i < A.size(); ++i){
	cout << A[i];
	if(i < A.size()-1) cout << ", ";
  }
  cout << '}' << endl;
}



void f(int m, conjunt A){
  if(m == n) return print(A);
  f(m+1, A);
  A.push_back(C[m]);
  f(m+1, A);
}



int main(){
  cin >> n;
  C = conjunt(n);
  for(int i = 0; i < n; ++i) cin >> C[i];
  conjunt A(0);
  f(0, A);
}
