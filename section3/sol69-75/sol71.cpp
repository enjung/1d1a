#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int ch[10001],d[3]={1,-1,5};//ch배열이 거리배열의 역할도 하게 함 

int main() {
	int i,s,e,x,pos;
	//freopen("input.txt","rt",stdin);
	scanf("%d %d",&s,&e);
	queue<int> Q;

	Q.push(s);
	ch[s]=1;
	
	//BFS탐색 
	while(!Q.empty()){ 
		x=Q.front();
		Q.pop();
		for(i=0;i<3;i++){
			pos=x+d[i];
			if(pos<=0 || pos>10000) continue;
			if(pos==e){
				printf("%d\n",ch[x]); //시작지점을 ch[s]=1이라고 했으므로 ch[x]+1이 아닌 ch[x]가 출력값 
				exit(0);
			}
			if(ch[pos]==0){
				ch[pos]=ch[x]+1; //x까지 가는 최소 점프 횟수 +1 이 pos까지 갈 수 있는 최소 점프횟수 
				Q.push(pos);
			}
		}
	}
	return 0;
}