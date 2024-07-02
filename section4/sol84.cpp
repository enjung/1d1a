#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, res=0;
vector<int> T,P;

void DFS(int L, int sum){
	if(L==n+1){
		if(sum>res){
			res=sum;
		}
	}
	else{
		if(L+T[L]<=n+1){ //무한루프 방지
			DFS(L+T[L],sum+P[L]);
		}
		DFS(L+1,sum);
		
	}
}

int main() {
	//freopen("input.txt","rt",stdin);
	int a,b;
	//날짜로 계산하기위해 벡터의 0번 인덱스는 사용하지 않음
	T.push_back(0);
	P.push_back(0);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		T.push_back(a);
		P.push_back(b);
	}
	DFS(1,0);
	printf("%d\n",res);
	return 0;
}