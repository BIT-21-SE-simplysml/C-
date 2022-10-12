#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		long long a[10];
		for(int i = 0; i < 10; i++){
			a[i] = 0;
		}
		long long n,k;
		cin >> n >> k;
		k++;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			int p = a[i];
			a[i] = 1;
			while(p > 0){
				a[i] *= 10;
				p--;
			}
		}
		long long ans = 0;
		for(int i = 1; i < n; i++){
			long long temp = a[i] - a[i - 1];
			long long nn = temp / a[i - 1];
			if(nn >= k){
				ans += k * a[i - 1];
				k = 0;
				break;
			}
			ans += temp;
			k -= nn;
		}
		if(k > 0){
			ans += k * a[n - 1];
		}
		cout << ans << endl;
	}
	return 0;
}
