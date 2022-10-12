#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int t = 0;
		int ans = 2;
		int p = 0;
		while(n > 0){
			int temp = n % 10;
			if(n / 10 == 0 && temp % 2 == 0)
				ans = min(1, ans);
			if(temp % 2 == 0 && t == 0)
				ans = min(0, ans);
			if(n % 2 == 0)
				p = 1;
			++t;
			n /= 10;
		}
		if(p == 0)
			ans = -1;
		cout << ans << endl;
	}
	return 0;
} 
