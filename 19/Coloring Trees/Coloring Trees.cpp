#include<bits/stdc++.h>
using namespace std;
long long f[105][105][105];
int	c[105];
int	p[105][105];
int main(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		cin >> c[i];
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= m; j++){
			cin >> p[i][j];
		}
	}
	for(int i = 0; i < 105; i++){
		for(int j = 0; j < 105; j++){
			for (int t = 0; t < 105; t++){
				f[i][j][t] = 0x3f3f3f3f3f3f3f3f;
			}
		}
	}
	if(c[0] != 0)
		f[0][1][c[0]] = 0;
	else{
		for(int i = 1; i <= m; i++){
			f[0][1][i] = p[0][i];
		}
	}
	for(int i = 1; i <= n - 1; i++){
		if(c[i] != 0){
			for(int j = 1; j <= k; j++){ 
				for (int t = 1; t <= m; ++t){ 
					if(c[i] == t)
	    	        	f[i][j][c[i]] = min(f[i][j][c[i]], f[i - 1][j][t]);
	            	else 
	            		f[i][j][c[i]] = min(f[i][j][c[i]], f[i - 1][j - 1][t]);
				}
			}
			continue;
		}
		for(int j = 1; j <= k; j++){
			for(int temp = 1; temp <= m; temp++){
				for(int t = 1; t <= m; t++){
					if(temp == t)
						f[i][j][temp] = min(f[i][j][temp], f[i - 1][j][t] + p[i][t]);
					else
						f[i][j][temp] = min(f[i][j][temp], f[i - 1][j - 1][t] + p[i][temp]);
				}
			}
		}
	}
	long long mn = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= m; i++){
		mn = min(mn, f[n - 1][k][i]);
	}
	if (mn == 0x3f3f3f3f3f3f3f3f)
		cout << -1;
	else cout << mn; 
	return 0;
}
