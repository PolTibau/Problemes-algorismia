#include<iostream>
using namespace std;

int main(){
	cout.setf(ios::fixed);
	cout.precision(4);
	double n, m;
	cin >> n >> m;
	if(m >= 1) cout << "mai" << endl;
	else cout << n/(1-m) << " segons" << endl;
	
}
