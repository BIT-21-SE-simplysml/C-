#include <bits/stdc++.h>
using namespace std;
int c[300005];
int mx;
map<int,int> mp;
int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	mx = 0;
	for(int i = 1; i <= n - k + 1; ++i){
		int ans = 0;
		for(int j = i; j <= i + k - 1; ++j){
			mp[c[j]] += 1;
			if(mp[c[j]] == 1) 
				ans += 1;
		}
		for(int j = i; j <= i + k - 1; ++j)
			mp[c[j]] = 0;
		if (ans > mx)
			mx = ans;
	}
	cout << mx;
}
