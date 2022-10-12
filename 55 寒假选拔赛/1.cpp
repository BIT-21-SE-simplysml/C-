#include<bits/stdc++.h> 
using namespace std;
int a[101];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 0; i < n; i++)
		if(a[i] == 0){
			int mn = 0x3f3f3f3f;
			if(i > 0)
				mn = min(mn, a[i - 1]);
			if(i < n - 1)
				mn = min(mn, a[i + 1]);
	//		cout << mn << ' ';
			ans += mn;
		}
	cout << ans << endl;
	return 0;
} 
