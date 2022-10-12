#include<bits/stdc++.h>
using namespace std;
long long c[505][505];
long long ans[505][505];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < 505; i++){
			for(int j = 0; j < 505; j++){
				c[i][j] = 0;
				ans[i][j] = 0x3f3f3f3f3f3f3f3f;
			}
		} 
		long long tot2 = 0;
		for(int i = 1; i <= 2 * n; i++){
			for(int j = 1; j <= 2 * n; j++){
				cin >> c[i][j];
				if(i > n && j > n || i <= n && j <= n){
					tot2 += c[i][j];
					ans[i][j] = 0;
				} 
			}
		}
		for(int i = 0; i < 505; i++){
			ans[i][0] = 0;
			ans[0][i] = 0;
			ans[2 * n + 1][i] = 0;
			ans[i][2 * n + 1] = 0;
		}
		long long tot = 0x3f3f3f3f3f3f3f3f;
		for(int i = 1; i <= 2 * n; i++){
			for(int j = 1; j <= 2 * n;j++){
				if(i > n && j > n || i <= n && j <= n){
					continue;
				}
				ans[i][j] = min(ans[i][j], ans[i - 1][j] + ans[i][j - 1] + c[i][j]);
			//	cout << ans[i][j] << endl;
				tot = min(ans[i][j], tot);
			}
		}
		for(int i = 1; i <= 2 * n; i++){
			for(int j = 2 * n; j > 0; j--){
				if(i > n && j > n || i <= n && j <= n){
					continue;
				}
				ans[i][j] = min(ans[i][j], ans[i - 1][j] + ans[i][j + 1] + c[i][j]);
				tot = min(ans[i][j], tot);
			}
		}
		for(int i = 2 * n; i > 0; i--){
			for(int j = 1; j <= 2 * n;j++){
				if(i > n && j > n || i <= n && j <= n){
					continue;
				}
				ans[i][j] = min(ans[i][j], ans[i + 1][j] + ans[i][j - 1] + c[i][j]);
				tot = min(ans[i][j], tot);
			}
		}
		for(int i = 2 * n; i > 0; i--){
			for(int j = 2 * n; j > 0; j--){
				if(i > n && j > n || i <= n && j <= n){
					continue;
				}
				ans[i][j] = min(ans[i][j], ans[i + 1][j] + ans[i][j + 1] + c[i][j]);
				tot = min(ans[i][j], tot);
			}
		}
		for(int i = 1; i <= 2 * n; i++){
			for(int j = 1; j <= 2 * n; j++){
				cout << ans[i][j] << ' ';
			}
			cout << endl;
		}
		cout << tot + tot2 << endl;
	}
	return 0;
} 
