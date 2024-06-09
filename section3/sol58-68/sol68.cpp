#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int ch[21],n,m,cost=2147000000;
vector<pair<int, int> > map[21];

void DFS(int v,int sum){
	if(v==n){
		if(sum<cost){
			cost=sum;
		}
	}
	else{
		for(int i=0;i<map[v].size();i++){
			//v는 현재 이미 탐색해 온 지점이고, 앞으로 탐색할 지점이 이미 방문한 지점인지 확인해야하는 것이므로
			//다음 방문할 지점은map[v][i].first임!! 
			if(ch[map[v][i].first]==0){
				ch[map[v][i].first]=1;
				DFS(map[v][i].first, sum+map[v][i].second);
				ch[map[v][i].first]=0;
			}
		}
		
	}
}

int main() {
	int i,a,b,c;
	//freopen("input.txt","rt",stdin);
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&a,&b,&c);
		map[a].push_back({b,c});
		//map[a].push_back(make_pair(b,c));와 동일 
	}
	ch[1]=1;
	DFS(1,0);
	printf("%d\n",cost);
	return 0;
}