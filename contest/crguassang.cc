#include<iostream>
using namespace std;

int main(){
	string s;
	while(cin >> s){
		cout << "le ";
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == 'r')cout << "rg";
			else if(s[i] == 'o' and i+1 < s.size() and s[i+1] == 'i'){
					cout << "ua";
					++i;
			}
			else if(i == s.size()-2 and s[i] == 'n' and s[i+1] == 't'){
				cout << "ng";
				break;
			}
			else cout << s[i];
		}
		cout << endl;
	}
}
