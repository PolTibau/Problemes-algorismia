#include<iostream>
#include<vector>
#include<stack>
#include<sstream>
using namespace std;


int main(){
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	vector<stack<string> > V(n);
	int i = 0;
	int k = n;
	while(k--){
		getline(cin, s);
		stringstream ss(s);
		string llibre;
		while(ss >> llibre) V[i].push(llibre);
		++i;
	}
	getline(cin, s);
	string accio;
	while(getline(cin, s)){
		stringstream ss(s);
		ss >> accio;
		if(accio == "PRESTEC"){
			int x;
			ss >> x;
			if(x > 0 and x <= n and V[x-1].size() > 0) V[x-1].pop();
		}
		else{
			int y;
			string retorna;
			ss >> retorna >> y;
			if(y > 0 and y <= n)V[y-1].push(retorna);
		}
	}
	for(int i = 0; i < n; ++i){
		cout << "Pila " << i+1 << ":";
		stack<string> aux;
		while(not V[i].empty()){
			aux.push(V[i].top());
			V[i].pop();
		}
		while(not aux.empty()){
			string coma = " ";
			cout << coma << aux.top();
			aux.pop();
		}
		cout << endl;
	}
}
