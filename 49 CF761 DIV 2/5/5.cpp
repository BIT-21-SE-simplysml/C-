#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int mx = 0;
		bool has_2 = false;
		bool has_1 = false;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			mx = max(mx, a[i]);
			if(a[i] % 3 == 2) has_2 = true;
			if(a[i] % 3 == 1) has_1 = true;
		}
		int ans = (mx - 1) / 3 + 2;
		if(has_1 == false && has_2 == false){
			cout << mx / 3 << endl;
			continue;
		}
		if(mx == 1){
			cout << 1 << endl;
			continue;
		}
		if(has_1 == false && mx % 3 != 0){
			ans--;
		}
		if(has_2 == false && mx % 3 != 0){
			ans--;
		}
		if(mx % 3 == 1 && has_1 && has_2){
			bool p = false;
			for(int i = 0; i < n; i++){
				if(a[i] == mx - 1){
					p = false;
					break;
				}
				if(a[i] % 3 == 2)
					p = true;
				if(a[i] == 1){
					p = false;
					break;
				}
			}
			if(p)
				--ans;
		}
		cout << ans << endl;
	}
}
