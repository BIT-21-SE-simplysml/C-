#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[105][105];
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= a[i][0]; ++j)
			cin >> a[i][j];
		int comon = a[i][1];
		int dif;
		int ans = 1;
		for(int j = 2; j <= a[i][0]; ++j)
			if(a[i][j] == comon) ++ans; 
			else dif = j;
		if (ans == 1) cout << '1' << '\n';
		else cout << dif << '\n';
	}
	return 0;
}
