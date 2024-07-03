#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,res,maxi=-2147000000,mini=2147000000;
vector<int> a;
int op[4];
void DFS(int L, int res){
	if(L==n){ //0부터 인덱스 사용했으므로 n-1까지 사용, n이 되면 종료 
		if(res<mini)mini=res;
		if(res>maxi)maxi=res;
	}
	else{
		if(op[0]>0){
			op[0]--;
			DFS(L+1,res+a[L]);
			op[0]++;
		}
		if(op[1]>0){
			op[1]--;
			DFS(L+1,res-a[L]);
			op[1]++;
		}
		if(op[2]>0){
			op[2]--;
			DFS(L+1,res*a[L]);
			op[2]++;
		}
		if(op[3]>0){
			op[3]--;
			DFS(L+1,res/a[L]);
			op[3]++;
		}
	}

}
int main() {
	//freopen("input.txt","rt",stdin);
	scanf("%d",&n);
	int i,x;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		a.push_back(x);
	}
	for(i=0;i<4;i++){
		scanf("%d",&op[i]);
	}
	DFS(1,a[0]);
	printf("%d\n",maxi);
	printf("%d\n",mini);
	return 0;
}