#include<bits/stdc++.h>
using namespace std;
char a[41][41];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		if(k > (n + 1) / 2){
			cout << -1 << endl;
			continue;
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				a[i][j] = '.';
		int t = 0;
		while(k--){
			a[t][t] = 'R';
			t += 2;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout << a[i][j];
			cout << endl;
		}
	}
	return 0;
} 
