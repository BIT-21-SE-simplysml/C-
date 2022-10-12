#include<bits/stdc++.h>
using namespace std;
int t[10005];
int	w[10005];
int	a[10005][2];
int main(){
	int ti, m;
	cin >> ti >> m;
	for(int i = 1; i <= m; i++){
		cin >> w[i] >> t[i]; 
	}
	for(int j = 1; j <= m; j++){
		for(int i = 1; i <= ti; i++){
			a[i][j % 2] = 0;
			if(i - t[j] >= 0)
				a[i][j % 2] = max(a[i - t[j]][j % 2] + w[j], max(a[i][(j + 1) % 2], a[i - t[j]][(j + 1) % 2] + w[j]));
			else a[i][j % 2] = a[i][(j + 1) % 2];
		}
	}
	cout << a[ti][m % 2];
	return 0;
}//gun dong array youhua
