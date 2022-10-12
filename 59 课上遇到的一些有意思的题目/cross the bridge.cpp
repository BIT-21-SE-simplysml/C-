//A nice problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1001];
ll tot;
void solve(int n){
	if(n == 1){
		tot += a[0];
		return;
	}
	if(n == 2){
		tot += a[1];
		return;
	}
	if(n == 3){
		tot += a[2] + a[1] + a[0];
		return;
	}
	tot += min(a[n - 2] + a[0],a[1] * 2) + a[n - 1] + a[0];
	solve(n - 2);
}
int main(){
	int n;
	while(scanf("%d", &n) == 1){
		tot = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		solve(n);
		cout << tot << endl;
	}
	return 0;
}