#include <stdio.h>
using namespace std;
int a[21][21],ch[21],n,m,cnt=0;

void DFS(int v){
	if(v==n){
		cnt++;
	}
	else{
		for(int i=1;i<=n;i++){
			if((a[v][i]==1)&&(ch[i]==0)){
				ch[i]=1;
				DFS(i);
				ch[i]=0;
			}
		}
	}
}

int main() {
	//freopen("input.txt","rt",stdin);
	int i,col,row;
	scanf("%d %d",&n,&m);
	//인접행렬 생성 
	for(i=1;i<=m;i++){
		scanf("%d %d",&row,&col);
		a[row][col]=1;
	}
	ch[1]=1;
	DFS(1);
	printf("%d\n",cnt);
	return 0;
}