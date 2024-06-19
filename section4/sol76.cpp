#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dy[21][21];
int DFS(int x, int y){
	if(dy[x][y]!=0){
		return dy[x][y];
	}
	if(x==y || y==0){
		return 1;
	}
	else{
		return dy[x][y]=DFS(x-1,y-1)+DFS(x-1,y);
	}
}

int main() {
	int n,r;
	//freopen("input.txt","rt",stdin);
	scanf("%d %d",&n,&r);
	printf("%d\n",DFS(n,r));
	return 0;
}