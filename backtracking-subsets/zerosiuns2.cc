 #include<iostream>
 #include<vector>
 using namespace std;

using VE = vector<int>;
using compte = vector<bool>;

int n, u;
VE v;

void print(){
    for(int i = 0; i < n-1; ++i) cout << v[i] << ' ';
    cout << v[n-1] << endl;
}


void f(int m, int uns){
  if(m == n) return print();
  if(m - uns < n - u){
    v[m] = 0;
    f(m+1, uns);
  }
  if(uns < u){
    v[m] = 1;
    f(m+1, uns+1);
  }
}

    


 int main(){
     cin >> n >> u;
     v = VE(n);
     f(0, 0);
 }
