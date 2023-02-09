#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	priority_queue<double> C;
	for(int i = 0; i < n; ++i){
		double t;
		cin >> t;
		t *= -1;
		C.push(t/100);
	}
	double suma = 0;
	while(C.size() > 1){
		double x = -C.top();
		C.pop();
		double y = -C.top();
		C.pop();
		C.push(-(x+y));
		suma += (x + y);
	}
	cout.setf(ios::fixed);
	cout.precision(4);
	cout << "nombre esperat de bits per lletra: " << suma << endl;
	
}
