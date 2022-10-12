#include<bits/stdc++.h>
using namespace std;
int a[1001];
int sum[1001];
long long f[1001][1001];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1; i <= n; ++ i){
		for(int j = i + 1; j <= n; ++j){
			for(int k = i; k <= j - 1; ++k){
				f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);
			}
		}
	}
	cout << f[1][n];
} 
