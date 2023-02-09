#include<iostream>
#include<vector>


using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vb = vector<bool>;

const long long MOD = 1e8+7;
int n, k;

vvvi memo;
int dp(int pos, int lleig, int ultim){
    //cerr << pos << lleig << ultim << endl;
    if(lleig == -1)
        return 0;
    int& res = memo[pos][lleig][ultim];
    
    if(res != -1) 
        return res;
        
    if(lleig > pos)
        return res = 0;
    res = 0;
    if(pos == 0){
        if(lleig == 0)
            return res = 1;
        return res = 0;
    }
    for(int i = 0; i < n; ++i){
        if(i-1 == ultim or i+1 == ultim)
            res = (res + dp(pos-1,lleig-1,i))%MOD;
        else
            res = (res + dp(pos-1,lleig,i))%MOD;
    }
    return res;
}
int main(){
    int t;
    while(cin >> n >> k >> t){
        
        memo = vvvi(n+1,vvi(k+1,vi(n,-1)));
        while(t--){
            int x,y;
            cin >> x >> y;
            for(int i = 0; i < n; ++i)
                if(i != y)
                    for(int j = 0; j <= k; ++j)
                        memo[x][j][i] = 0;
             
        }
        int sol = 0;
        for(int i = 0; i < n; ++i)
            sol = (sol + dp(n-1,k,i))%MOD;
        cout << sol << endl;
    }
    
}
