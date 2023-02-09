#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int f, c;
int timer = 0;
using VB = vector<int>;
using VVB = vector<VB>;
VVB vist(100, VB(100));
VVB dist(100, VB(100));

const VB stepx = {1,2,2,1,-1,-2,-2,-1};
const VB stepy = {-2,-1,1,2,2,1,-1,-2};

bool ok(int x, int y){
	return(x >= 0 and y >= 0 and x < c and y < f);
}


int BFS(int inii, int inij){
	++timer;
	queue<int> qx;
	queue<int> qy;
	qx.push(inii);
	qy.push(inij);
	dist[inii][inij] = 0;
	vist[inii][inij] = timer;
	int ans = 0;
	while(not qx.empty()){
		int x0 = qx.front();
		int y0 = qy.front();
		qx.pop(); qy.pop();
 		ans = max(ans, dist[x0][y0]);
		for(int i = 0; i < 8; ++i){
			int x1 = x0 + stepx[i];
			int y1 = y0 + stepy[i];
			if(ok(x1,y1) and vist[x1][y1] < timer){
				vist[x1][y1] = timer;
				dist[x1][y1] = dist[x0][y0] + 1;
				qx.push(x1);
				qy.push(y1);
			}
		}
	}
	return ans;
}


int main(){
	int p;
	while(cin >> c >> f >> p){
		for(int x = 0; x < c; ++x){
			for(int y = 0; y < f; ++y){
				vist[x][y] = 0;
			}
		}
		for(int i = 0; i < p; ++i){
			int x, y;
			cin >> x >> y;
			vist[x-1][y-1] = 99999999;
		}
		int maxim = 0;
		for(int i = 0; i < c; ++i){
			for(int j = 0; j < f; ++j){
				if(vist[i][j] < 99999999)maxim = max(BFS(i,j), maxim);
			}
		}
		cout << maxim << endl;
	}
}
