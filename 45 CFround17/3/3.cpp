#include<bits/stdc++.h>
using namespace std;

int a[200005];
int b[200005];
int n;

bool check(int mid){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(b[i] >= cnt && a[i] >= mid - cnt - 1)
			++ cnt;
	}
	return cnt < mid ? 1 : 0;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		int left = 1;
		int right = n;
		for(int i = 0; i < n; i++){
			scanf("%d %d" , &a[i], &b[i]);
		}
		while(left <= right){
			int mid = (left + right) >> 1;
			if(check(mid)) right = mid - 1;
			else left = mid + 1; 
		}
		cout << left - 1 << endl;
	}
	return 0;
}
