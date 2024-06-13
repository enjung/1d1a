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
				printf("%d\n",pQ.top()); //루트값, front()아니고 top()!! 
				pQ.pop();
			}
		}
		else{
			pQ.push(x);
		}	
	}
	return 0;
}