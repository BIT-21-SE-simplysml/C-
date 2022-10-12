#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans = 0;
		for(int i = 1; i <= n; i++){
			int temp;
			cin >> temp;
			ans = max(ans,temp - i);
		}
		cout << ans << endl;
	}
	return 0;
} 
