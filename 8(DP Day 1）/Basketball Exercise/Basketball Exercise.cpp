#include<bits/stdc++.h>
using namespace std;
int c[2][100005];
long long a[2][100005];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> c[0][i];
	}
	for(int i = 1; i <= n; i++)
		cin >> c[1][i];
	a[0][0] = 0;
	a[1][0] = 0;
	a[0][1] = c[0][1];
	a[1][1] = c[1][1];
	for(int j = 2; j <= n; j++){
		for(int i = 0; i <= 1; i++)
			a[i][j] = max(1ll * c[i][j] + a[1 - i][j - 2],1ll * c[i][j] + a[1 - i][j - 1]);
	}
	cout << max(a[0][n],a[1][n]);
	return 0;
}
