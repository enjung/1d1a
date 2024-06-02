#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int a[21][21];

int main() {
	//freopen("input.txt","rt",stdin);
	int i,col,row,tmp,n,m;
	scanf("%d %d",&n,&m);

	for(i=1;i<=m;i++){
		scanf("%d %d %d",&row,&col,&tmp);
		a[row][col]=tmp;
	}
	for(row=1;row<=n;row++){
		for(col=1;col<=n;col++){
			printf("%d ",a[row][col]);
		}
		puts("");
	}
	return 0;
}