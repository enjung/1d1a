#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int ch[101];

struct Edge{
	int vex;
	int dis;
	Edge(int a,int b){
		vex=a;
		dis=b;
	}
	//최소힙 유지를 위한 연산자 오버로딩 
	bool operator<(const Edge &b)const{
		return dis>b.dis;
	}
};

int main() {
	//freopen("input.txt","rt",stdin);
	priority_queue<Edge> Q; 
	vector<pair<int, int> > graph[21];
	int n,m,i,a,b,c;
	scanf("%d %d",&n,&m);
	vector<int> dist(n+1,2147000000); //거리를 무한대로 초기화했다고 생각 
	
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&a,&b,&c);
		graph[a].push_back(make_pair(b,c));
	}
	
	Q.push(Edge(1,0)); //첫 기준노드를 1로 잡음, 가중치는 0으로 
	dist[1]=0; //1번 정점에서 1번 정점으로 가는 최소비용은 0 
	while(!Q.empty()){
		Edge tmp=Q.top(); //큐에서 거리비용 가장 적은 게 tmp가 됨
		Q.pop();
		int now = tmp.vex;
		int cost = tmp.dis;
		if(cost>dist[now]){
			continue;
		}
		for(i=0;i<graph[now].size();i++){
			int next=graph[now][i].first;
			int nextDis=cost+graph[now][i].second;
			if(nextDis<dist[next]){
				dist[next]=nextDis;
				Q.push(Edge(next,nextDis));
			}
		}		
	}
	
	for(i=2;i<=n;i++){
		if(dist[i]!=2147000000){
			printf("%d : %d\n",i,dist[i]);
		}
		else{
			printf("%d : impossible\n",i);
		}
	}
	return 0;
}