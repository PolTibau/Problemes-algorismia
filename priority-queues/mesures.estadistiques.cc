#include<iostream>
#include<queue>
#include<sstream>
using namespace std;

void estadistica(priority_queue<int>& A, priority_queue<int>& I, double suma){
	if(I.empty()){
		while(not A.empty()) A.pop();
		cout << "no elements" << endl;
	}
	else{
		cout << "minimum: " << -I.top() << ',';
		cout << " maximum: " << A.top() << ',';
		double mitjana = suma / I.size();
		cout.setf(ios::fixed);
		cout.precision(4);
		cout << " average: " << mitjana << endl;
	}
}


int main(){
	string s;
	double suma = 0;
	priority_queue<int> A, I;
	while(getline(cin, s)){
		stringstream ss(s);
		string x;
		ss >> x;
		if(x == "number"){
			int y;
			ss >> y;
			suma += y;
			A.push(y);
			I.push(-y);
			estadistica(A, I, suma);
		}
		else{
			if(not I.empty()) suma -= -I.top();
			if(I.size() > 0) I.pop();
			estadistica(A, I, suma);
		}
	}
}
