#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Data{
	int money;
	int day;
	Data(int a, int b){
		money=a;
		day=b;
	}
	bool operator<(Data &d){
		return day>d.day; //기한이 긴 것부터 확정해야하므로 내림차순 
	}
};

int main() {
	//freopen("input.txt","rt",stdin);
	int n,m,d,i,j,outcome=0,max=-2147000000;
	vector<Data> T;
	priority_queue<int> pQ;//큐에는 강연료 만 넣으면 됨
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&m,&d);
		T.push_back(Data(m,d));
		if(d>max) max=d;
	}
	sort(T.begin(),T.end());
	
	//i는 강연하는 날짜, j는 벡터 T에서 사용하는 인덱스 
	for(i=max,j=0;i>=1;i--){
		for(;j<n;j++){
			if(T[j].day<i)break; 
			//i일에는 해당 강연을 할 수 없단 뜻, i랑 비교를 해야 내가 만든 에러 고칠 수 있음
			//정렬한 T에서 강연마감일이 항상 연속적이지 않기 때문
			//(7일이 마감인 강연 5개, 다음이 2일이 마감인 강연이라면 3~7일까지 7일마감강연 다섯개를 다 할 수 있음)
			pQ.push(T[j].money);
			//i일에 할 수 있는 강연이라면 강연료들을 push 
		}
		if(!pQ.empty()){
			outcome+=pQ.top();
			pQ.pop();
		}	
	}
	printf("%d\n",outcome);
	return 0;
}