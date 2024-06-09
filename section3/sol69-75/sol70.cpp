#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int ch[21],dis[21],n,m;
vector<int> map[21];
queue<int> Q;

int main() {
	int i,a,b,x;
	//freopen("input.txt","rt",stdin);
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		map[a].push_back(b);
	}
	Q.push(1);
	ch[1]=1;
	while(!Q.empty()){
		x=Q.front();
		Q.pop();
		for(i=0;i<map[x].size();i++){
			if(ch[map[x][i]]==0){
				ch[map[x][i]]=1;
				Q.push(map[x][i]);
				dis[map[x][i]]=dis[x]+1; //x를 거치고, 1만큼을 더 가야 map[x][i]로 갈 수 있음 
			}
		}
	}
	
	for(i=2;i<=n;i++){
		printf("%d : %d\n",i,dis[i]);
	}
	return 0;
}