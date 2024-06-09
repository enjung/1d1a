#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
void rec(int x){
	if(x==0){ //재귀 종료지점 설정 
		return; 
	}
	else{
		rec(x-1);
		printf("%d ",x);
	}
}

int main() {
	//freopen("input.txt","rt",stdin);
	int n;
	scanf("%d",&n);
	rec(n);
	return 0;
}