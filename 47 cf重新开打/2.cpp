#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<int, bool> mp;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			mp[i] = false;
		}
		sort(a + 1, a + n + 1);
		for(int i = 2; i < 2 + n / 2; i++){
			cout << a[i] << ' ' << a[1] << endl;
		}
	}
	return 0;
}
