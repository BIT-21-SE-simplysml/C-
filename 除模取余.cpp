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
	int t;
	cin >> t;
	while(t--){
		int a,b,k;
		long long temp1,temp2;
		cin >> a >> b >> k;
		if(k % 2 == 1){
			temp1 = ((1ll * half(2,k / 2)) * ((a + b) % md)) % md;
			temp2 = ((1ll * half(2,k / 2)) * ((a - b + md) % md)) % md;
		}
		if(k % 2 == 0){
			temp1 = (1ll * half(2,k / 2) * a) % md;
			temp2 = (1ll * half(2,k / 2) * b) % md; 
		}
		cout << temp1 << ' ' << temp2 << endl; 
	}
	return 0;
}
