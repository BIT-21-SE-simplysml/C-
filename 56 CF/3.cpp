#include<bits/stdc++.h>
using namespace std;
int d[501];
int a[501];
long long dp[501][501];

int main(){
	int n, l, k;
	cin >> n >> l >> k;
	for(int i = 0; i < n; i++){
		cin >> d[i];
	}
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < 501; i++){
		for(int j = 0; j < 501; j++)
			dp[i][j] = 0x3f3f3f3f3f3f3f3f; 
	}
	dp[0][0] = 0;
	d[n] = l; 
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++){
			for(int u = 0; u < i; u++){
				if(j < i && j >= i - u - 1){
					dp[i][j] = min(dp[i][j], dp[u][j - (i - u - 1)] + (d[i] - d[u]) * a[u]);
				}
			}
		}
	}
  // for (int i=0;i<=n;i++)
   //{
     // for (int j=0;j<=min(i,k);j++)
      //{
        // cout << dp[i][j] <<  ' ';
      //}
     // cout << '\n';
   //}
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for(int j = 0; j <= k ; j++){
	//	cout << dp[n][j] << ' ';
		ans = min(dp[n][j], ans);
	}
	cout << ans << endl;
	return 0;
}
