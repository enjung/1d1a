#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int n,a[10],total=0;
bool flag=false;

void DFS(int L,int sum){
	if(sum>(total/2)){
		return;
	}
	if(flag==true){
		return;
	}
	if(L==n+1){ //재귀 종료지점 설정
		if(sum==total-sum){
			flag=true;
		}
		return;
	}
	else{
		DFS(L+1,sum+a[L]);
		DFS(L+1,sum);
	}
}

int main() {
	//freopen("input.txt","rt",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		total+=a[i];
	}
	DFS(1,0);
	if(flag){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}