#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int unf[1001];

//집합번호를 return, 이때 집합번호는 v의 루트노드(해당 집합에서 가장 마지막으로 union한 노드) 
int Find(int v){
	if(v==unf[v]) return v;
	else{
		return unf[v]=Find(unf[v]);
	}
	//메모이제이션을 위해 unf[v]에 저장하고 return 
	//트리의 level 낮아지는 효과
}

void Union(int a, int b){
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}

int main() {
	//freopen("input.txt","rt",stdin);
	int n,m,i,a,b;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		unf[i]=i; //unf초기화 
	}
	for(i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		Union(a,b);
	}
	
	scanf("%d %d",&a,&b);
	if(Find(a)==Find(b)) printf("YES\n");
	else printf("NO\n");
	return 0;
}