#include<bits/stdc++.h>
using namespace std;
long long mi[61];
int main(){
	int t;
	cin >> t;
	for(int i = 0; i < 61; i++){
		mi[i] = 1ll << i;
	}
	while(t--){
		long long n,k;
		long long t1 = 0;
		cin >> n >> k;
		if(n == 1){
			cout << 0 << endl;
			continue;
		}
		n--;
		long long ans = 0;
		while(mi[t1] <= k && n > 0){
			ans++;
			n = n - mi[t1];
			t1++;
		//	cout << mi[t1] << endl;
			if(n <= 0){
				cout << ans << endl;
				break;
			}
		}
		if(n > 0){
			ans += (((n - 1) / k) + 1); 
		}
		if(n > 0){
			cout << ans << endl;
		}
	}
	return 0;
}
