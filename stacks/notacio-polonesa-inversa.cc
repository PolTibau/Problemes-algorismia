#include<iostream>
#include<stack>
#include<sstream>
using namespace std;

int canvi(string c){
	int n = c.size();
	int suma = 0;
	for(int i = 0; i < n; ++i){
		suma += c[i] - '0';
		if(i+1 < n) suma *= 10;
	}
	return suma;
}



int main(){
	string s;
	while(getline(cin, s)){
		stack<int> P;
		stringstream ss(s);
		string c;
		while(ss >> c){
			if(c != "+" and c != "-" and c != "*"){
				P.push(canvi(c));
			}
			else{
					int x, y;
					x = P.top();
					P.pop();
					y = P.top();
					P.pop();
					if(c == "+")P.push(x+y);
					else if(c == "-")P.push(-x+y);
					else P.push(x*y);
			}
		}
		cout << P.top() << endl;
	}
}
