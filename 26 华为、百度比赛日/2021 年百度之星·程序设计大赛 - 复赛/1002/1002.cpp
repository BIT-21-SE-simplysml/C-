#include<bits/stdc++.h>
using namespace std;
const int md = 1000000007;
long long n,m,t;
long long dp[3001][3001]; 
int main(){
	cin >> t;
	dp[0][0] = 0;
	for(int i = 1; i <= 3000; i++){
		dp[0][i] = 1;
		dp[i][0] = 1;
	}
	for(int i = 1; i <= 3000; i++){
		for(int j = 1; j <= 3000; j++){
			dp[i][j] = (dp[i][j - 1] * 2 + dp[i - 1][j] * 2) % md;
		}
	}
	while(t--){
		cin >> n >> m;
		cout << dp[n][m] << endl;
	}
	return 0;
}
