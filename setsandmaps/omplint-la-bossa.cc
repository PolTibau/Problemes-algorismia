#include<iostream>
#include<set>
using namespace std;
using ll = long long;

int main(){
	int n;
	ll v;
	string ac;
	cin >> n;
	set<ll> bossa;
	set<ll> joies;
	ll suma = 0;
	while(cin >> ac >> v){
		if(ac == "deixar"){
			if(bossa.size() < n){
				suma += v;
				bossa.insert(v);
			}
			else{
				if(v > *bossa.begin()){
					bossa.insert(v);
					suma += v - *bossa.begin();
					joies.insert(*bossa.begin());
					bossa.erase(*bossa.begin());
				}
				else joies.insert(v);
			}
		}
		else{
			if(bossa.count(v) == 1){
				suma -= v;
				bossa.erase(v);
				if(joies.size() > 0){
					ll entra = *(--joies.end());
					bossa.insert(entra);
					joies.erase(entra);
					suma += entra;
				}
			}
			else joies.erase(v);
		}
		/*for(auto it = bossa.begin(); it != bossa.end(); ++it) cout << *it << ' ';
		cout << endl;
		for(auto it = joies.begin(); it != joies.end(); ++it) cout << *it << ' ';
		cout << endl;*/
		cout << suma << endl;
	}
}
