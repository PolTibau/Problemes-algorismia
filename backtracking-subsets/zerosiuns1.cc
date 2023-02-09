#include<iostream>
#include<vector>
using namespace std;

using VE = vector<int>;

int n;
VE v;

void print(){
    for(int i : v) cout << v[i] << ' ';
    cout << v[n-1] << endl;
}

void f(int m){
  if(m == n) return print();
  else{
    v[m] = 0;
    f(m+1);
    v[m] = 1;
    f(m+1);
  }
}


int main(){
    cin >> n;
    v = VE(n);
    f(0);
}
