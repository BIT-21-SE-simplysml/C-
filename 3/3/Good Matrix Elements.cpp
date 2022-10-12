#include <bits/stdc++.h>
using namespace std;
int a[105][105]; 
int main(){
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			a[i][j] = 0;
			if(i == j)
				a[i][j] = 1;
			if((i + j) == (n + 1))
				a[i][j] = 1;
			if((i == (n+1) / 2) || (j == (n+1) / 2))
				a[i][j] = 1;
			int temp;
			cin >> temp;
			ans += temp * a[i][j];
		}
	}
	cout << ans;
	return 0;
}
