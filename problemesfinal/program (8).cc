#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> V;

void rec(vector<bool>& U, vector<string>& F, int t) { 
    vector<bool> TU = U;
    for (int i=0; i<n; i++) {
        int co = -1;
        for (int j=0; j<2*n; j++) {
            if (not TU[j]) {
                bool ma = true;
                for (int k=0; k<t; k++) if (F[i][k] != V[j][k]) ma = false;
                if (ma) co = j;
            }
        }
        if (co == -1) return; // F[0 .. t] cannot be matched
        else TU[co] = true;
    }
    
    if (t == n) {
        for (int i=0; i<n; i++) { 
            for (int j=0; j<n; j++) cout << F[j][i];
            cout << endl;
        }
        cout << endl;
    }
    
    for (int i=0; i<2*n; i++) {
        if (not U[i]) {
            U[i] = true;
            for (int j=0; j<n; j++) F[j][t] = V[i][j];
            
            rec(U, F, t+1);
            
            U[i] = false;
        }
    }
}

int main() {
    while (cin >> n) {
        V = vector<string>(2*n);
        for (auto &x : V) cin >> x;
        sort(V.begin(), V.end());
        
        vector<bool> U(2*n, false);
        vector<string> F(n, string(n, '?'));
        rec(U, F, 0);
        
        cout << "----------" << endl;
    }
}
