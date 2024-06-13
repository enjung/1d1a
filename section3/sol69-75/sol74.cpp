#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	//freopen("input.txt","rt",stdin);
	int x;
	priority_queue<int> pQ;
	
	while(true){
		scanf("%d",&x);
		if(x==-1) break;
		if(x==0){
			if(pQ.empty()){
				printf("-1\n");
			}
			else{
				printf("%d\n",-pQ.top()); //마이너스를 붙여 저장했으므로 출력할때 원복
				pQ.pop();
			}
		}
		else{
			pQ.push(-x); //마이너스를 붙여야 작은 값이 트리의 위쪽에 위치할 수 있음
		}	
	}
	return 0;
}