// from https://codeforces.com/contest/1612/problem/C;
#include<bits/stdc++.h>
using namespace std;
long long k,x;

bool check1(long long mid){
	long long ans = 1ll * (1 + mid) * mid / 2;
	if(ans >= x)
		return true;
	return false; 
}

bool check2(long long mid){
	long long ans = 1ll * mid * (k - 1 + k - mid) / 2;
	if(ans >= x)
		return true;
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> k >> x;
		if(x >= k * k){
			cout << 2 * k - 1 << endl;
			continue;
		}
		long long temp = k * (k + 1) / 2;
		if(temp > x){
			long long l = 1; long long r = k;
			while (l <= r){
				long long mid = (l + r) >> 1;
				if(check1(mid)) r = mid - 1;
				else l = mid + 1;
			}
			cout << l << endl;
		}
		if(temp == x){
			cout << k << endl;
			continue;
		}
		if(temp < x){
			x -= temp;
			long long l = 1; long long r = k - 1;
			while (l <= r){
				long long mid = (l + r) >> 1;
				if(check2(mid)) r = mid - 1;
				else l = mid + 1;
			}
			cout << r - 1 << endl;
		}
	}
	return 0;
}
