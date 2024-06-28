#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dis[101];
struct Edge{
	int s;
	int e;
	int val;
	Edge(int a,int b,int c){
		s=a;
		e=b;
		val=c;
	}
};
int main() {
	//freopen("input.txt","rt",stdin);
	int n,m,i,j,a,b,c,s,e;
	scanf("%d %d",&n,&m);
	vector<Edge> Ed;
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&a,&b,&c);
		Ed.push_back(Edge(a,b,c));
	}
	for(i=2;i<=n;i++){
		dis[i]=2147000000;
	}
	scanf("%d %d",&s,&e);
	//i는 거쳐가는 간선의 개수, 최대 n-1까지만 고려
	//j는 정점번호-1 
	for(i=1;i<n;i++){
		for(j=0;j<Ed.size();j++){
			int u=Ed[j].s;
			int v=Ed[j].e;
			int w=Ed[j].val;
			if(dis[u]!=2147000000 && dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
			}
		}
	}
	
	//간선을 n번 거쳐서 최소비용이 갱신된다면 음의 사이클이 있는 것으로 판단 
	for(j=0;j<Ed.size();j++){
		int u=Ed[j].s;
			int v=Ed[j].e;
			int w=Ed[j].val;
			if(dis[u]!=2147000000 && dis[u]+w<dis[v]){
				printf("-1\n");
				exit(0);
			}
	}
	
	printf("%d\n",dis[e]);
	return 0;
}