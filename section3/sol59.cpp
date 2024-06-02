#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int n,ch[11];
void DFS(int L){
	if(L==n+1){ //재귀 종료지점 설정
		for(int i=1;i<=n;i++){
			if(ch[i]==1){
				printf("%d ",i);
			}
		}
		printf("\n");
		return; 
	}
	else{
		ch[L]=1;
		DFS(L+1);
		ch[L]=0;
		DFS(L+1);
	}
}

int main() {
	//freopen("input.txt","rt",stdin);
	scanf("%d",&n);
	DFS(1);
	return 0;
}