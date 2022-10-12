#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long w,h;
		cin >> w >> h;
		int n;
		cin >> n;
		long long ans = 0;
		long long mx = 0; long long mn = 0x3f3f3f3f;
		for(int i = 0; i < n; i++){
			long long temp;
			cin >> temp;
			mx = max(temp, mx);
			mn = min(temp, mn); 
		}
		ans = max((mx - mn) * h, ans);
		cin >> n;
		mx = 0; mn = 0x3f3f3f3f;
		for(int i = 0; i < n; i++){
			long long temp;
			cin >> temp;
			mx = max(temp, mx);
			mn = min(temp, mn); 
		}
		ans = max((mx - mn) * h, ans);
		cin >> n;
		mx = 0; mn = 0x3f3f3f3f;
		for(int i = 0; i < n; i++){
			long long temp;
			cin >> temp;
			mx = max(temp, mx);
			mn = min(temp, mn); 
		}
		ans = max((mx - mn) * w, ans);
		cin >> n;
		mx = 0; mn = 0x3f3f3f3f;
		for(int i = 0; i < n; i++){
			long long temp;
			cin >> temp;
			mx = max(temp, mx);
			mn = min(temp, mn);
		}
		ans = max((mx - mn) * w, ans);
		cout << ans << endl;
	}
	return 0;	
}
