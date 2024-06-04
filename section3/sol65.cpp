#include <stdio.h>
using namespace std;
int maze[9][9],ch[9][9],cnt=0;
//12시,3시,6시,9시 순
int dx[4]={0,1,0,-1}; 
int dy[4]={-1,0,1,0};

void DFS(int x,int y){
	int i,xx,yy; //앞으로 이동할 지점이 (xx,yy) 
	if(x==7 && y==7){
		cnt++;
	}
	else{
		for(i=0;i<4;i++){
			xx=x+dx[i];
			yy=y+dy[i];
			if(xx<1||xx>7||yy<1||yy>7){
				continue;
			}
			if(maze[xx][yy]==0 && ch[xx][yy]==0){
				ch[xx][yy]=1;
				DFS(xx,yy);
				ch[xx][yy]=0;
			}
		}
	}
}

int main() {
	//freopen("input.txt","rt",stdin);
	int i,j;
	for(i=1;i<=7;i++){
		for(j=1;j<=7;j++){
			scanf("%d",&maze[i][j]);
		}
	}
	ch[1][1]=1;
	DFS(1,1);
	printf("%d\n",cnt);
	return 0;
}