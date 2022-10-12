#include <bits/stdc++.h>
using namespace std;\
char c[105];
int main(){
	int t;
	cin >> t;
	while (t--){
		int n,a,b;
		int ans = 0;
		c[0] = 'l';
		cin >> n >> a >> b;
		for(int i = 1;i <= n; i++){
			cin >> c[i];
			if(c[i] != c[i - 1]) ++ ans;
		}
//		cout << ans << endl;
//		cout << a << endl << b << endl << n << endl;
		int total;
		if(b > 0)
			total = a * n + b * n;
		else 
			total = a * n + b * (ans / 2 + 1);
		cout << total << endl;
	}
	return 0;
}
