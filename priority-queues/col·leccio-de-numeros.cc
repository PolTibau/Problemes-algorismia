#include<iostream>
#include<queue>
#include<sstream>
using namespace std;


void translate(priority_queue<int>& C, char c, stringstream& ss, bool& error){
	if(C.empty() and c != 'S') error = true;
	else if(c == 'A') cout << C.top() << endl;
	else if(c == 'S'){
		int y;
		ss >> y;
		C.push(y);
		
	}
	else if(c == 'R') C.pop();
	else if(c == 'I'){
		int y;
		ss >> y;
		int max = C.top();
		C.pop();
		C.push(max+y);
	}
	else if(c == 'D'){
		int y;
		ss >> y;
		int max = C.top();
		C.pop();
		C.push(max-y);
	}
}



int main(){
	string s;
	priority_queue<int> C;
	while(getline(cin, s)){
		stringstream ss(s);
		char c;
		bool error = false;
		while(ss >> c)translate(C, c, ss, error);
		if(error) cout << "error!" << endl;
	}
}
