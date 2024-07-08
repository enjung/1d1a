#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int map[9][9],dis[9][9];
struct Loc{
	int x;
	int y;
	Loc(int a,int b){
		x=a;
		y=b;
	}
};
queue<Loc> Q;

int main() {
	//freopen("input.txt","rt",stdin);
	int i,j,cnt=0;
	
	for(i=1;i<=7;i++){
		for(j=1;j<=7;j++){
			scanf("%d",&map[i][j]);
		}
	}
	Q.push(Loc(1,1)); //출발점
	map[1][1]=1;
	
	while(!Q.empty()){
		Loc tmp = Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int xx=tmp.x+dx[i];
			int yy=tmp.y+dy[i];
			if(map[xx][yy]==0 && xx>=1 &&xx<=7&&yy>=1&&yy<=7){
				Q.push(Loc(xx,yy));
				map[xx][yy]=1;
				dis[xx][yy]=dis[tmp.x][tmp.y]+1;
			}
		}
	}
	
	printf("%d\n",dis[7][7]);
	return 0;
}