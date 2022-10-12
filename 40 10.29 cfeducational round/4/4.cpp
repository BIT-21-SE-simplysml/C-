#include<bits/stdc++.h>
using namespace std;
const int md = 998244353;
long long half(int j, int k){
	if (k == 0){
		return(1);
	}
	if((k % 2) == 0){
		long long tem;
		tem = half(j, k / 2);
		return (1ll * tem * tem) % md;
	}
	else {
		return ((1ll * half(j, k - 1)) * j) % md;
	}
}

int main(){
	int n,x;
	cin >> n >> x;
//	cout << half(4,5) << endl;
	if(x <= n - 1){
		cout << half(x,n) << endl;
	}
	if(x > n - 1){
		int temp = (half(n - 1,n) - half(n - 2, n) + md) % md;
		long long ans = 1ll * (x - n + 1) * temp + half(n - 1,n);
		ans %= md;
		cout << ans << endl;
	}
	return 0;
}
