#include<bits/stdc++.h>
using namespace std;
int a[150001];
int last[150001];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < 150001; i++){
			last[i] = -1;
		}
		int ans = 666666;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(last[a[i]] != -1)
			ans = min(ans, i - last[a[i]]);
			last[a[i]] = i;
		}
		if(ans > n)
			cout << -1 << endl;
		else cout << n - ans << endl;
	}
	return 0;
}
