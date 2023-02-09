#include<iostream>
#include<stack>
#include<sstream>
using namespace std;

int main(){
	string s;
	while(getline(cin, s)){
		bool palindrom = true;
		stringstream ss(s);
		stack<int> P, S, aux;
		int x;
		while(ss >> x){
			P.push(x);
			aux.push(x);
		}
		while(not aux.empty()){
			S.push(aux.top());
			aux.pop();
		}
		
		while(not P.empty() and palindrom){
			if(S.top() != P.top()) palindrom = false;
			else{
				P.pop();
				S.pop();
			}
		}
		if(palindrom) cout << "Es un palindrom." << endl;
		else cout << "NO es un palindrom." << endl;
	}
}
