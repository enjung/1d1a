#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int Q[100],front=-1,back=-1,ch[10];
vector<int> map[10];

int main() {
	//freopen("input.txt","rt",stdin);
	//노드가 n개면 간선은 n-1개, 이때 n은 6으로 고정하고 작성 
	int a,b,i,x;
	for(i=1;i<=6;i++){
		scanf("%d %d",&a,&b);
		map[a].push_back(b);
		map[b].push_back(a); //무방향 그래프로 가정함 
	}
	
	//루트노드 넣기
	 Q[++back]=1; //Q[0]=1번 루트노드 
	 ch[1]=1; //방문함을 체크함
	 
	//back은 큐에 넣을때 사용, front는 큐에서 뺄 때 사용 
	 while(front<back){
	 	x=Q[++front];
	 	printf("%d ",x);
	 	for(i=0;i<map[x].size();i++){
	 		if(ch[map[x][i]]==0){
	 			ch[map[x][i]]=1;
	 			Q[++back]=map[x][i];
			}
		 }
	 }
	return 0;
}