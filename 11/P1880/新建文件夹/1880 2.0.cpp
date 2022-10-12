#include<bits/stdc++.h>
using namespace std;
int a[1001];
int sum[1001];
int f1[1001][1001];
int f2[1001][1001];
int main(){
	int n;
	cin >> n;
	sum[0] = 0;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		a[n + i] = a[i];
	}
	for(int i = 1; i <= 2 * n; ++i){
		sum[i] = sum[i - 1] + a[i];
	}
	for(int j = 1; j < n; ++j){
		for(int i = 1; i + j <= 2 * n; ++ i){
			f1[i][i + j] = 0;
			f2[i][i + j] = 100000000;
			for(int k = i; k <= i + j - 1; ++k){
				f1[i][i + j] = max(f1[i][i + j], f1[i][k] + f1[k + 1][i + j] + sum[i + j] - sum[i - 1]);
				f2[i][i + j] = min(f2[i][i + j], f2[i][k] + f2[k + 1][i + j] + sum[i + j] - sum[i - 1]);
			}
		}
	}
/*	for(int i = 1; i <= n; ++i){
		for(int j = i; j <= n; ++j){
			cout << f[i][j] << ' ';
		}
		cout << endl;
	}*/
	int mn,mx;
	mx = 0;
	mn = 1000000000;
	for(int i = 1; i <= n; i++){
		mx = max(mx, f1[i][n + i - 1]);
		mn = min(mn, f2[i][n + i - 1]);
	}
//	cout << f2[5][6] << endl;
	cout << mn << endl << mx;
	return 0;
}
