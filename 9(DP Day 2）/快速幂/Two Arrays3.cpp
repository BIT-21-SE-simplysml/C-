#include<bits/stdc++.h>
using namespace std;
const int md = 1000000007;
long long temp[1001];

long long half(int j, int k){
	if (k == 0){
		return(1);
	}
	if((k % 2) == 0){
		long long tem;
		tem = half(j, k / 2);
//		cout << (1ll * tem * tem) % md;
		return (1ll * tem * tem) % md;
	}
	else {
//		cout << ((1ll * half(j, k - 1)) * j) % md;
		return ((1ll * half(j, k - 1)) * j) % md;
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		temp[i] = 1;
		for(int j = i; j <= i + m - 2; j++){
			if(m - 1 == 0)
				break;
			temp[i] *= (1ll * j);
			temp[i] %= md;
		}//A<M - 1, I + m - 2>
		for(int j = 2; j <= m - 1; j++){
/*			if(m - 1 == 0)
				break;    */
			temp[i] *= (1ll * half(j,md - 2));
			temp[i] %= md;
//			cout << temp[i] << endl;
//			cout << temp[i] << endl;
//			cout << half(j,md - 2) << endl;
		}
	}
	long long ans = 0;
	for(int i = 1; i <= n; ++ i){
		for(int j = i; j <= n; ++ j){
			ans += (temp[i] * temp[n + 1 - j]) % md;
		}
	} 
	cout << (ans % md);
	return 0;
}
