#include<bits/stdc++.h>
using namespace std;
const int MAX = 2 * 1e5 + 5;
long long h[MAX];
int n;
long long d[MAX];

bool check(long long mid){
	for(int i = n; i >= 3; i--){
		if(h[i] + d[i + 1] + 2 * d[i + 2] >= mid){
			d[i] = min((h[i] + d[i + 1] + 2 * d[i + 2] - mid), h[i]) / 3;
		}
		else d[i] = 0;
	}
	long long mn = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= n; i++){
		mn = min(h[i] + d[i + 1] + 2 * d[i + 2] - d[i] * 3, mn);
	}
	if(mn >= mid)
		return false;
	return true;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> h[i];
		}
		h[n + 1] = 0;
		d[n + 1] = 0;
		d[n + 2] = 0;
		int l = 0; int r = 1e9 + 1;
		while(l <= r){
			long long mid = (l + r) >> 1;
			if(check(mid)) 
				r = mid - 1;
			else l = mid + 1;
		}
		cout << l - 1 << endl;
	}
	return 0;
}
