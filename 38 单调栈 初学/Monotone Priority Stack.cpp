#include<bits/stdc++.h>
using namespace std;
int ans[3000001]; 
int main(){
	stack<int> MPS;
	int n;
	scanf("%d", &n);
	int num = 0;
	for(int i = 1; i <= n; i++){
		int temp;
		scanf("%d", &temp);
		while(!MPS.empty() && MPS.top() > temp){
			MPS.pop();
			printf("%d ", i - MPS.size());
		}
		MPS.push(temp);
	}
} 
