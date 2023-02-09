#include<iostream>
using namespace std;


int main(){
	cout.setf(ios::fixed);
	cout.precision(4);
	double n, a, t;
	cin >> n >> a >> t;
	if(a <= t) cout << "mai" << endl;
	else{
		double temps = n/(a-t);
		cout << temps << " segons" << endl;
	}
}
