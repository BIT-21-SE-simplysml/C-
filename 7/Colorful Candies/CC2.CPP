#include <bits/stdc++.h>
using namespace std;
int c[300005];
int mx;
int ans;
map<int,int> mp;
int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	mx = 0;
	for(int i = 1; i <= k; ++i){
			mp[c[i]] += 1;
			if(mp[c[i]] == 1) {
				ans += 1;
			}
	}
	mx = ans;
	for(int i = k + 1; i <= n; ++i){
		mp[c[i - k]] -= 1;
		if(mp[c[i - k]] == 0)
			--ans;
		mp[c[i]] += 1;
		if(mp[c[i]] == 1)
			++ans;
		if (mx < ans)
			mx = ans;
//		cout << ans << endl;
	}
//	for(int i = 1; i <= n; ++i)
//		cout << mp[c[i]] << ' ';
	cout << mx;
	return 0;
}
