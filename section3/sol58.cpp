#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//전위 순회 -> 1 2 4 5 3 6 7
void D(int v){
	if(v>7){ //재귀 종료지점 설정
		return; 
	}
	else{
		printf("%d ",v); 
		D(v*2);    //왼쪽 자식노드 
		D(v*2+1);  //오른쪽 자식노드 
	}
}

//중위 순회 -> 4 2 5 1 6 3 7
/*
void D(int v){
	if(v>7){ //재귀 종료지점 설정
		return; 
	}
	else{
		D(v*2);    //왼쪽 자식노드
		printf("%d ",v);
		D(v*2+1);  //오른쪽 자식노드 
	}
}
*/

//후위 순회 -> 4 5 2 6 7 3 1
/*
void D(int v){
	if(v>7){ //재귀 종료지점 설정
		return; 
	}
	else{
		D(v*2);    //왼쪽 자식노드 
		D(v*2+1);  //오른쪽 자식노드 
		printf("%d ",v);
	}
}
*/
int main() {
	//freopen("input.txt","rt",stdin);
	D(1);
	return 0;
}