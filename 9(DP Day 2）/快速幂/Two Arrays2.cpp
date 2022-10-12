#include<bits/stdc++.h>
using namespace std;
const long long md = 1000000007;
long long temp[11][1001];
int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		temp[i][1] = 1;
	}
	for(int i = 1; i <= n; ++i){
		temp[1][i] = 1;
	}
	for(int t = 2; t <= m; ++t){
		for(int i = 2; i <= n; ++i){
			for(int j = 1; j <= i; ++j){
				temp[t][i] += temp[t - 1][j];
				temp[t][i] %= md;
			}
		}
	}
	for(int i = 1; i <= n; ++ i)
		cout << temp[m][i] << endl;
//	cout << temp[m][1];
	long long ans = 0;
	for(int i = 1; i <= n; ++ i){
		for(int j = i; j <= n; ++ j){
			ans += (temp[m][i] * temp[m][n + 1 - j]) % md;
//			cout << i << ' '<<j << ' ' << temp[m][n + 1 - j] <<' '<< temp[m][i] <<endl;
		}
	} 
	cout << (ans % md);
	return 0;
}
