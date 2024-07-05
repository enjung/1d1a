#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,dis,sum=0,res=2147000000,comb[12];
vector<pair<int,int> > pz;
vector<pair<int,int> > hs;


void DFS(int L, int s){
	if(L==m){
		sum=0;
		
		//i로 집을 먼저 택하고, 그 집으로부터의 가장가까운 피자집들의 거리를 구함 
		for(int i=0;i<hs.size();i++){
			int x1=hs[i].first;
			int y1=hs[i].second;
			dis=2147000000; //집 하나 고를때마다 dis는 초기화
			 
			//j는 comb배열의 인덱스, 이를 이용해 pz배열의 인덱스로 활용 
			for(int j=0;j<m;j++){
				int x2=pz[comb[j]].first;
				int y2=pz[comb[j]].second;
				dis=min(dis,abs(x1-x2)+abs(y1-y2));
				//dis=abs(x1-x2)+abs(y1-y2);
			}
			sum+=dis;
		}
		if(sum<res) res=sum;
	
	}
	else{
		//조합구하기 
		for(int i=s;i<pz.size();i++){
			comb[L]=i;
			DFS(L+1,i+1);
		}
	}
}

int main() {
	//freopen("input.txt","rt",stdin);
	int x,i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&x);
			if(x==1){
				hs.push_back(make_pair(i,j));
			}
			if(x==2){
				pz.push_back(make_pair(i,j));
			}
		}
	}
	
	//피자집 중에서 m개 고르는 combination을 comb배열에 저장 
	DFS(0,0);
	printf("%d\n",res);
	return 0;
}