#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,r,i,j,cnt=0;
int a[20],res[20],ch[20];

void DFS(int L){
	if(L==r){
		cnt++;
		for(int j=0;j<L;j++){
			printf("%d ",res[j]); 
		}
		puts("");
		
	}
	else{
		for(int i=1;i<=n;i++){
			if(ch[i]==0){
				res[L]=a[i]; //res에는 0번 인덱스부터 저장 
				ch[i]=1;
				DFS(L+1);
				ch[i]=0; //다시 체크 풀어주기 
			}
		}
	}
}

int main() {
	//freopen("input.txt","rt",stdin);
	scanf("%d %d",&n,&r);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	DFS(0);
	printf("%d\n",cnt);
	return 0;
}