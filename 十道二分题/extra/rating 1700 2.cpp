//https://codeforces.com/problemset/problem/439/D
#include<bits/stdc++.h>
using namespace std;

int n,m;
int basic;
int a[100001];
int b[100001];
long long sa[100002];
long long sb[100002];

bool check1(int mid){
	if(a[mid] >= basic)return true;
	return false;
}

bool check2(int mid){
	if(b[mid] >= basic)return true;
	return false;
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sa[n + 1] = sa[n];
	for(int i = 1; i <= m; i++){
		cin >> b[i];
	}
	sort(a + 1,a + 1 + n);
	sort(b + 1, b + 1 + m);
	for(int i = 1; i <= n; i++){
		sa[i] = 1ll * a[i] + sa[i - 1];
	}	
	for(int i = m; i >= 0; i--){
		sb[i] = sb[i + 1] + b[i];
	}
	long long ans = 1e18;
	for(int i = 1; i <= n + m; i++){
		basic = (i <= n) ? a[i] : b[i - n];
		int l = 1, r = n;
		while(l <= r){
			int mid = l + r >> 1;
			if(check1(mid)){
				r = mid - 1;
			}
			else l = mid + 1;
		}
		l--;
	//	cout << basic << ": " << l << endl;
		long long ans1 = 1ll * basic * l - sa[l];
	//	cout << ans1 << endl;
		l = 1; r = m; 
		while(l <= r){
			int mid = l + r >> 1;
			if(check2(mid)){
				r = mid - 1;
			}
			else l = mid + 1;
		}
		long long ans2 = sb[l] - 1ll * basic * (m - l + 1);
//		cout << basic << ": " << l << ' ' << sb[l] << ' ' << ans2 << endl;
//		cout << basic << ": " << ans1 << ' ' << ans2 << endl;
		ans = min(ans1 + ans2 , ans);
	}
	cout << ans << endl;
	return 0;
}
