#include<iostream>
#include<vector>
using namespace std;

string s;
int n, d;
using VB = vector<bool>;
VB vist;
int ref = 'A' - 0;



bool compleix(char c, int d){
	int x = s.size()-1;
	int origen = (c - 0) - ref;
	if(x-origen >= d or origen - x >= d)return true;
	return false;
}


void f(int i){
	if(i == n){
		cout << s << endl;
		return;
	}
	for(int k = 0; k < n; ++k){
		if(not vist[k]){
			vist[k] = true;
			s.push_back(char(ref+k));
			if(compleix(char(ref+k), d))f(i+1);
			s.pop_back();
			vist[k] = false;
		}
	}
}




int main(){
	cin >> n >> d;
	vist = VB(n, false);
	f(0);
	
}
