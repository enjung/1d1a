#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int unf[10001];

struct Edge{
	int v1;
	int v2;
	int val;
	Edge(int a,int b,int c){
		v1=a;
		v2=b;
		val=c;
	}
	//연산자 오버로딩, 오름차순으로. 
	bool operator<(Edge &b){
		return val<b.val;
	}
};

int Find(int v){
	if(v==unf[v]) return v;
	else{
		return unf[v]=Find(unf[v]);
	}
}

void Union(int a, int b){
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}

int main() {
	//freopen("input.txt","rt",stdin);
	vector<Edge> Ed; 
	int n,m,i,a,b,c,res=0;
	scanf("%d %d",&n,&m);
	
	for(i=1;i<=n;i++){
		unf[i]=i;
	}
	
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&a,&b,&c);
		Ed.push_back(Edge(a,b,c));
		
	}
	//가중치값에의해 오름차순 정렬 
	sort(Ed.begin(), Ed.end());
	
	for(i=0;i<m;i++){
		int fa=Find(Ed[i].v1);
		int fb=Find(Ed[i].v2);
		if(fa!=fb){
			res+=Ed[i].val;
			Union(Ed[i].v1,Ed[i].v2);
		}
	}
	printf("%d\n",res);
	return 0;
}