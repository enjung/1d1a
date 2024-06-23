#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int ch[101];

struct Edge{
	int e;
	int val;
	Edge(int a,int b){
		e=a;
		val=b;
	}
	//최소힙 유지를 위한 연산자 오버로딩 
	bool operator<(const Edge &b)const{
		return val>b.val;
	}
};

int main() {
	//freopen("input.txt","rt",stdin);
	priority_queue<Edge> Q; 
	vector<pair<int, int> > map[101];  //가중치 인접리스트 
	int n,m,i,a,b,c,res=0;
	scanf("%d %d",&n,&m);
	
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&a,&b,&c);
		//무방향가중치인접리스트
		map[a].push_back(make_pair(b,c));
		map[b].push_back(make_pair(a,c));
	}
	
	Q.push(Edge(1,0)); //첫 기준노드를 1로 잡음, 가중치는 0으로 
	while(!Q.empty()){
		Edge tmp=Q.top(); //큐에서 가중치 가장 작은 게 tmp가 됨
		Q.pop();
		if(ch[tmp.e]==0){ //가중치 작은 엣지가 아직 연결안된 노드와 연결되는 엣지라면, 
			ch[tmp.e]=1;
			res+=tmp.val;
			//트리로 선택된 지금의 노드와 연결된 엣지들을 큐에 push 
			for(i=0;i<map[tmp.e].size();i++){
				Q.push(Edge(map[tmp.e][i].first, map[tmp.e][i].second));
			}
		}
	}
	printf("%d\n",res);
	return 0;
}