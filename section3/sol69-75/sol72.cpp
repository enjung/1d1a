#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int i,n,k,x,cnt=0;
	//freopen("input.txt","rt",stdin);
	scanf("%d %d",&n,&k);
	queue<int> Q;
	for(i=1;i<=n;i++){
		Q.push(i);
	}

	while(Q.size()!=1){
		cnt++;
		x=Q.front();
		if(cnt!=k){
	  		Q.push(x);
		}
		else{
			cnt=0;
		}
        Q.pop();
	}
	printf("%d\n",Q.front());
	return 0;
}