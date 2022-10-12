// from https://codeforces.com/problemset/problem/1476/A
#include<bits/stdc++.h>
using namespace std;

long long n,k;

bool check(long long mid){
	if(n * mid >= k)
		return true;
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		if(k < n){
			int temp = (n - 1) / k + 1;
			k *= temp;
		}
		long long l = 1;
		long long r = k;
		while(l <= r){
			long long mid = (l + r) >> 1;
			if(check(mid))
				r = mid - 1;
			else l = mid + 1;
		}
		cout << l << endl;
	}
}
