#include<iostream>
#include<string>
#include<map>
#include<set>
#include<sstream>
using namespace std;

string s, persona, accio;


int main(){
	string s;
	set<string> C;
	map<string, int> M;
	while(getline(cin, s)){
		stringstream ss(s);
		ss >> persona >> accio;
		if(accio == "enters"){
			if(C.count(persona) == 0){
				C.insert(persona);
				M[persona] = 0;
			}
			else cout << persona << " is already in the casino" << endl;
		}
		else if(accio == "leaves"){
			if(C.count(persona) == 0) cout << persona << " is not in the casino"<< endl;
			else{
				cout << persona << " has won " << M[persona] << endl;
				C.erase(persona);
			}
		}
		else{
			int q;
			ss >> q;
			auto it = M.find(persona);
			if(C.count(persona)) it->second += q;
			else cout << persona << " is not in the casino" << endl;
		}
	}
	cout << "----------" << endl;
	for(auto x : C){
		cout << x << " is winning " << M[x] << endl;
	}
}
