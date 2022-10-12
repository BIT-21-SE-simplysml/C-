#include<bits/stdc++.h>
using namespace std;

int a[105];
int b[105];

bool cmp(int x, int y){
	return x > y;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		for(int i = 0; i < 105; i++){
			b[i] = 0;
			a[i] = 0;
		}
		int n,k;
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n, cmp);
		long long ans = 0;
		for(int i = 2 * k; i < n; i++)
			ans += a[i];
		int t = 0;
		b[t]++;
		for(int i = 1; i < 2 * k; i++){
			if(a[i] != a[i - 1])
				t++;
			b[t]++;
		}
		t++;
		sort(b, b + t, cmp);
		for(int i = 1; i < t; i++){
			b[0] -= b[i];
		}
		if(b[0] > 0)
			ans += b[0] / 2;
		cout << ans << endl;
	}
	return 0;
}
