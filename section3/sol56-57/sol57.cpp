#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
void bin(int x){
	if(x==0){ //재귀 종료지점 설정
		return; 
	}
	else{
		bin(x/2);
		printf("%d",x%2);
	}
}

int main() {
	//freopen("input.txt","rt",stdin);
	int n;
	scanf("%d",&n);
	bin(n);
	return 0;
}