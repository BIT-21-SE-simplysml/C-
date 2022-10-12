#include <bits/stdc++.h>
using namespace std;
int a[10][10];b[10][10];
int main(){
	int t;
	cin >> t;
	while (t--){
		for(int i = 1; i <= 9; ++i){
			cin >> a[i][0];
			for(int j = 9; j >= 1; --j){
				a[i][j] = a[i][0] % 10;
				a[i][0] /= 10;
				b[i][j] = a[i][j];
			}
		}
		
	}

} 
