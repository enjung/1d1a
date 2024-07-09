#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int map[1002][1002],dis[1002][1002];
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
	int i,j,m,n,max=-2147000000;
	scanf("%d %d",&m,&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]==1){
				Q.push(Loc(i,j));
			}
		}
	}

	while(!Q.empty()){
		Loc tmp = Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int xx=tmp.x+dx[i];
			int yy=tmp.y+dy[i];
            //m,n 주의! xx/yy는 좌표임
			if(map[xx][yy]==0 && xx>=1 && xx<=n && yy>=1 && yy<=m){
				Q.push(Loc(xx,yy));
				map[xx][yy]=1;
				dis[xx][yy]=dis[tmp.x][tmp.y]+1;
			}
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(dis[i][j]>=max){
				max=dis[i][j];
			}
			if(map[i][j]==0){
				printf("-1\n");
				exit(0);
			}
		}
	}
	
	printf("%d\n",max);
	return 0;
}