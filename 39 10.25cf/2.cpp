#include<bits/stdc++.h>
using namespace std;
int a[2001][101];
int b[2001];
int num[2001];
int main(){
	int t;
	cin >> t;
	while(t--){
		for(int i = 0; i < 2001; i++){
			for(int j = 1; j < 101; j++){
				a[i][j] = 0;
			}
			a[i][0] = i;
		}
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> b[i];
			a[b[i]][1]++;
		}
		for(int i = 2; i < 101; i++){
			for(int j = 0; j < 2001; j++)
				num[j] = 0;
			for(int j = 0; j < n; j++){
				++num[a[b[j]][i - 1]];
			}
			for(int j = 0; j < n; j++){
				a[b[j]][i] = num[a[b[j]][i - 1]];
			}
		}
		int m;
		cin >> m;
		for(int i = 0; i < m; i++){
			int x,k;
			cin >> x >> k;
			if(k > 100)
				k = 100;
			cout << a[b[x - 1]][k] << endl;
		}
	}
	return 0;
} 
