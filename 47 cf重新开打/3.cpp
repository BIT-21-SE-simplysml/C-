#include<bits/stdc++.h>
using namespace std;

long long a[101];
long long h;
int n;

bool check(long long mid){
	long long ans = 0;
	for(int i = 1; i < n; i++){
		if(a[i] - a[i - 1] <= mid){
			ans += (a[i] - a[i - 1]);
		}
		else ans += mid;
		if(ans >= h)
			return true;
	}
	ans += mid;
	if(ans >= h)
		return true;
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> h;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		long long l = 1;
		long long r = 1e18;
		while(l <= r){
			long long mid = (l + r) >> 1;
			if(check(mid)){
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << l << endl;
	}
	return 0;
}
