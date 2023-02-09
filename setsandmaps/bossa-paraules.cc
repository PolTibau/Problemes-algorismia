#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;



int main(){
	map<string, int> B;
	string mini, maxi, s;
	while(cin >> s){
		if(s == "store" or s == "delete"){
			string paraula;
			cin >> paraula;
			if(s == "store"){
				if(not B.count(paraula))B.insert({paraula, 1});
				else B[paraula]++;
			}
			else{
				if(B[paraula] > 1)B[paraula]--;
				else B.erase(paraula);
			}
		}
		else if(s == "minimum?"){
			if(B.empty()) cout << "indefinite minimum" << endl;
			else cout << "minimum: " << (*(B.begin())).first << ", " << (*(B.begin())).second << " time(s)" << endl;
		}
		else if(s == "maximum?"){
			if(B.empty()) cout << "indefinite maximum" << endl;
			else cout << "maximum: " << (*(--B.end())).first << ", " << (*(--B.end())).second << " time(s)" << endl;
		}
	}
}
