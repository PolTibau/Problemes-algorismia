#include<iostream>
#include<set>
using namespace std;

int main(){
    set <string> R, S;
    string median;
    cin>>median;
    if (median != "END"){
    cout<<median<<endl;
    S.insert(median);
    string s;
    while (cin>>s){
        if (s=="END") break;
        else{
            if (s<median) R.insert(s);
            else S.insert(s);

            if (S.size()>R.size()+2){
                for (auto x: S){
                R.insert(x);
                S.erase(x);
                break;
                }
            }
            else{
							if (R.size()==S.size()){
								for (auto it=R.rbegin(); it != R.rend(); --it){
									S.insert(*it);
									R.erase(*it);
									break;
                }
							}
            }
            for (auto x: S){
                median = x;
                break;
            }
            cout<<median<<endl;
            }
    }
}
}
