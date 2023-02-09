#include<iostream>
using namespace std;


int d;


void tira_amunt(int& i, int& j, int k, int& metres){
	for(int s = 0; metres < d and s < k; ++s){
		i+=1;
		metres+=1;
		cout << "(" << i*100 << ", " << j*100 << ")" << endl;
	}
}

void tira_esquerra(int& i, int& j, int k, int& metres){
	for(int s = 0;metres < d and s < k; ++s){
		j-=1;
		cout << "(" << i*100 << ", " << j*100 << ")" << endl;
		metres+=1;
	}
}

void tira_avall(int& i, int& j, int k, int& metres){
	for(int s = 0;metres < d and s < k; ++s){
		i-=1;
		cout << "(" << i*100 << ", " << j*100 << ")" << endl;
		metres+=1;
	}
}

void tira_dreta(int& i, int& j, int k, int& metres){
	for(int s = 0;metres < d and s < k; ++s){
		j+=1;
		cout << "(" << i*100 << ", " << j*100 << ")" << endl;
		metres+=1;
	}
}



int main(){
	cin >> d;
	cout << "(0, 0)" << endl;
	int i = 0;
	int j = 0;
	int k = 0;
	int metres = 0;
	int x = 0;
	while(metres < d){
		if(x%2 == 0)k++;
		if(x%4 == 0)tira_dreta(i,j,k,metres);
		else if(x%4 == 1)tira_avall(i,j,k,metres);
		else if(x%4 == 2)tira_esquerra(i,j,k,metres);
		else tira_amunt(i,j, k, metres);
		++x;
	}
}
