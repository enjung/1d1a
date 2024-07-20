#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4]={-1,0,1,0}; //x는 행번호,12시부터 시계방향으로 
int dy[4]={0,1,0,-1};
int map[27][27],ch[27][27];
struct State{
	int x,y,dis;
	State(int a,int b,int c){
		x=a;
		y=b;
		dis=c;
	}
	bool operator<(const State &bb)const{
		if(dis==bb.dis){
			if(x==bb.x){ //거리가 같고 x가 같으면,
				return y>bb.y; //이때 y는 열값. 즉 더 왼쪽에 있는 게 우선순위 높음 
			}
			else{ //거리가 같고,x가 다르면,
				return x>bb.x;   //이때 x는 행값임. 즉 더 위에 있는게 우선순위 높음 
			}
		}
		else{ //거리가 다르면 거리가 가까운데가 우선순위 높음 
			return dis>bb.dis;
		}
	}
};
struct Lion{
	int x,y,size,ate;
	void sizeUp(){
		size++;
		ate=0;
	}
};

int main() {
	//freopen("input.txt","rt",stdin);
	int i,j,n,res=0;
	priority_queue<State> PQ;
	Lion simba;
	scanf("%d",&n);
	for(i=1;i<=n;i++){ //j가 y좌표가 되기 위해서 
		for(j=1;j<=n;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]==9){
				PQ.push(State(i,j,0));
				map[i][j]=0;
				simba.x=i;
				simba.y=j;
				simba.size=2;
				simba.ate=0;
			}
		}
	}
	
	while(!PQ.empty()){
		State tmp = PQ.top();
		PQ.pop();
		int x = tmp.x;
		int y = tmp.y;
		int z = tmp.dis;
		
		//심바가 잡아먹을 수 있는 토끼인지 판별	
		if(map[x][y]!=0 && map[x][y]< simba.size){ 
			//잡아먹기
			simba.x = x;
			simba.y = y;
			simba.ate++;
			if(simba.ate==simba.size){
				simba.sizeUp();
			}
			map[x][y]=0; //잡아먹은 토끼의 좌표는 0 
			
			//체크배열 초기화
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					ch[i][j]=0;
				}
			}
			while(!PQ.empty()){
				PQ.pop();
			}
			res=tmp.dis; //res는 현재까지 움직인 총 거리 
		}
		
		
		//심바가 현재 있는 위치로부터 상하좌우에 갈 좌표를 정함 
		for(i=0;i<4;i++){
			int xx = x+dx[i];
			int yy = y+dy[i];
			if(xx<1|| xx>n || yy<1 || yy>n || map[xx][yy]>simba.size || ch[xx][yy]>0) continue;
			else{
				PQ.push(State(xx,yy,z+1));
				ch[xx][yy]=1;
			}
		}
	}
	
	printf("%d\n",res);
	return 0;
}