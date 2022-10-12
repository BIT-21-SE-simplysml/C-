#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[200001];
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		if(n == 1){
			cout << a[0] << endl;
			continue;
		}
		sort(a,a + n);
		int temp = min(a[0],0);
		for(int i = 0; i < n; i++)
			a[i] -= temp;
		int ans = a[0];
		for(int i = 1; i < n; i++){
			ans = max(ans,a[i] - a[i - 1]);
		}
		cout << ans << endl;
	}
	return 0;
} 
