#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int ch[21],n,m,cnt=0;
vector<int> map[21];

void DFS(int v){
	if(v==n){
		cnt++;
	}
	else{
		for(int i=0;i<map[v].size();i++){
			if(ch[map[v][i]]==0){
				ch[map[v][i]]=1;
				DFS(map[v][i]);
				ch[map[v][i]]=0;
			}
		}
	}
}

int main() {
	//freopen("input.txt","rt",stdin);
	int i,a,b;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		map[a].push_back(b);
	}
	ch[1]=1;
	DFS(1);
	printf("%d\n", cnt);
	return 0;
}