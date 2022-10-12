#include<bits/stdc++.h>
using namespace std;
const int MAX = 2 * 1e5 + 5;
int a[101];
int num[101];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < 101; i++){
			num[i] = 0;
		}
		for(int i = 0; i < n; i++){
			cin >> a[i];
			num[abs(a[i])]++;
		}
		int ans = 0;
		if(num[0] > 0)
			++ans;
		for(int i = 1; i < 101; i++){
			if(num[i] <= 2){
				ans += num[i];
			}
			else ans += 2;
		}
		cout << ans << endl;
	}
	return 0;
} 
