#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int a[10],ch[10];
//a[0]=D, a[1]=E, a[2]=M, a[3]=N, a[4]=O, a[5]=R, a[6]=S, a[7]=Y 
int send(){
	return a[6]*1000 +a[1]*100 +a[3]*10 +a[0];
}
int more(){
	return a[2]*1000 +a[4]*100 +a[5]*10 +a[1];
}
int money(){
	return a[2]*10000 +a[4]*1000 +a[3]*100 +a[1]*10 +a[7];
}
void DFS(int L){
	if(L==8){
		if(send()+more()==money()){
			if(a[2] == 0 || a[6] == 0) return;
			printf("  %d %d %d %d\n", a[6], a[1], a[3], a[0]);
			printf("+ %d %d %d %d\n", a[2], a[4], a[5], a[1]);
			printf("---------\n");
			printf("%d %d %d %d %d\n", a[2], a[4], a[3], a[1], a[7]);
		}		
	}
	else{
		//순열만들기 
		for(int i=0;i<10;i++){
			if(ch[i]==0){
				a[L]=i; //a배열의 앞에서부터 i를 키워가며 대입해보기
				ch[i]=1; //i라는 숫자를 사용했다는 체크
				DFS(L+1);
				ch[i]=0;
			}
		}
	}
}

int main() {
	//freopen("input.txt","rt",stdin);
	DFS(0);
	return 0;
}