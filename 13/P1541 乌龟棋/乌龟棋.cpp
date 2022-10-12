#include<bits/stdc++.h>
using namespace std;
int a[351];
int b[121];
int m[5];
int f[41][41][41][41];
int main(){
	int n,l;
	cin >> n >> l;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= l; i++){
		cin >> b[i];
		++ m[b[i]];
	}
	f[0][0][0][0] = a[1];
	for(int i = 0; i <= m[1]; i++){
		for(int j = 0; j <= m[2]; j++){
			for(int k = 0; k <= m[3]; k++){
				for(int p = 0; p <= m[4]; p++){
					int temp = 1 + i + 2 * j + 3 * k + 4 * p;
					if(i > 0)
						f[i][j][k][p] = max(f[i][j][k][p], f[i - 1][j][k][p] + a[temp]);
					if(j > 0)
						f[i][j][k][p] = max(f[i][j][k][p], f[i][j - 1][k][p] + a[temp]);
					if(k > 0)
						f[i][j][k][p] = max(f[i][j][k][p], f[i][j][k - 1][p] + a[temp]);
					if(p > 0)
						f[i][j][k][p] = max(f[i][j][k][p], f[i][j][k][p - 1] + a[temp]);
//					cout << f[i][j][k][p] << endl;
				}
			}
		}
	}
	cout << f[m[1]][m[2]][m[3]][m[4]];
}
