#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int map[21][21],ch[21],n,m,cost=0,res=2147000000;

void DFS(int v,int sum){
	int i;
	if(v==n){
		if(sum<res){
			res=sum;
		}
	}
	
	else{
		for(i=1;i<=n;i++){
			if(ch[i]==0 && map[v][i]!=0){
				ch[i]=1;
				DFS(i,sum+map[v][i]);
				ch[i]=0;
			}
		}
	}
}

int main() {
	//freopen("input.txt","rt",stdin);
	int i,a,b,c;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&a,&b,&c);
		map[a][b]=c;
	}
	ch[1]=1;
	DFS(1,0);
	printf("%d\n", res);
	return 0;
} 