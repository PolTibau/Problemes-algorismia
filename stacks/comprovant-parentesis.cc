#include<iostream>
#include<stack>
using namespace std;


bool correcta(stack<char>& C, string s){
	for(int i = 0; i < s.size(); ++i){
		char c = s[i];
		if(c == ']' or c == ')'){
			if(C.empty()) return false;
			char e = C.top();
			C.pop();
			if((c == ']' and e != '[') or (c == ')' and e != '(')) return false;
		}
		else C.push(c);
	}
	if(C.empty()) return true;
	return false;
}


int main(){
	string s;
	while(cin >> s){
		stack<char> C;
		if(correcta(C, s)) cout << s << " es correcta" << endl;
		else cout << s << " es incorrecta" << endl;
	}
}
