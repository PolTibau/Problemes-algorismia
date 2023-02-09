#include<iostream>
#include<set>
#include<map>
using namespace std;

int main(){
    map <string, string> M;
    string ord;
    while(cin >> ord){
        if(ord == "liats"){
            string a, b;
            cin >> a >> b;

            if(M.count(a) == true and M[a] != "lalalla"){
                string c = M[a];
                M[c] = "lalalla";

            }
            if(M.count(b) == true and M[b] != "lalalla"){
                string d = M[b];
                M[d] = "lalalla";
            }

            M[a] = b;
            M[b] = a;
        }
        else{
            set <string> S;
            set <pair <string, string>> L;
            for(auto x : M){
                if(x.second == "lalalla") S.insert(x.first);
                    else{
                        if(x.first > x.second) L.insert(make_pair(x.second, x.first));
                        if(x.first <= x.second) L.insert(make_pair(x.first, x.second));
                    }

                }

            cout << "PARELLES:" << endl;
            for(auto x : L) cout << x.first << " " << x.second << endl;
            cout << "SOLS:" << endl;
            for(auto x : S) cout << x << endl;
            cout << "----------" << endl;
        }

    }

}
