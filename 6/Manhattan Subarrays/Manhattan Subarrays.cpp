#include <bits/stdc++.h>
using namespace std;
int b[200005];
bool p;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			cin >> b[i];
		}
		for(int i = 1; i <= n - 2; ++i){
			p = true; 
			for(int k = i + 2; k <= n; ++k){
				++ans;
				for(int j = i + 1; j < k; ++j){
					for(int m = i; m < j; ++m){
						if (((b[m] >= b[j]) && (b[j] >= b[k])) || ((b[m] <= b[j]) && (b[j] <= b[k]))){
							p = false;
							break;
						}
					}
				}
				if (p == false){
					ans -= 1;
					break;
				}
			}
		}
		ans += (n + n - 1); 
		cout << ans << endl;
	}
}
