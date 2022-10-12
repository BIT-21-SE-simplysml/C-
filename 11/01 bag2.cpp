#include<bits/stdc++.h>
using namespace std;
int t[10005];
int	w[10005];
int	a[10005];
int main(){
	int ti, m;
	cin >> ti >> m;
	for(int i = 1; i <= m; i++){
		cin >> t[i] >> w[i]; 
	}
	for(int j = 1; j <= m; j++){
		for(int i = ti;i >= 1; i--){
			if(i - t[j] >= 0)
				a[i] = max(a[i], a[i - t[j]] + w[j]);
		}
	}
	cout << a[ti];
	return 0;
}
