#include<bits/stdc++.h>
using namespace std;
int a[100004];
long long s[100004];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		long long m;
		scanf("%d%lld",&n, &m);
		long long mx = 0;
		s[0] = 0;
		long long temp = 0;
		long long smx = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			s[i] = a[i] + s[i - 1]; smx = max(smx, s[i]);
			temp += a[i];
			if(temp < 0)
				temp = 0;
			mx = max(temp, mx);
		}
		if(mx >= m){
			cout << 1 << endl;
			continue;		
		}
		if(temp + smx >= m){
			cout << 2 << endl;
			continue;
		}
		if(s[n] <= 0){
			cout << -1 << endl;
			continue;
		}
		m -= smx;
		m -= temp;
//		cout << m << endl;
		cout << (1ll * 3 + ((m - 1) / s[n])) << endl;
	}
	return 0;
}
