#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int n,a[10],b[10];

void divide(int lt, int rt){
	int mid,p1,p2,p3;
	if(lt<rt){
		//분할 
		mid=(lt+rt)/2;
		divide(lt,mid);
		divide(mid+1,rt);
		
		//이제 병합 
		for(p1=lt,p2=mid+1,p3=lt;(p1<=mid)&&(p2<=rt);p3++){
			if(a[p1]<a[p2]){
				b[p3]=a[p1++];
			}
			else{
				b[p3]=a[p2++];
			}
		}
		
		//아직 병합되지 못하고 끝난 집합이 있을 수 있으므로 
		while(p1<=mid){
			b[p3++]=a[p1++];
		}
		while(p2<=rt){
			b[p3++]=a[p2++];
		}
		
		//b배열에 정렬한 값을 a배열에 적용하기
		for(int i=lt;i<=rt;i++){
			a[i]=b[i];
		} 
		
	}
}
int main() {
	//freopen("input.txt","rt",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	divide(1,n);
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}