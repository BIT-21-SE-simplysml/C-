#include<bits/stdc++.h>
using namespace std;
int red[1000001];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < 1e6 + 1; i++){
			red[i] = 0x3f3f3f3f;
		}
		int mx = 1e6 + 1;
		for(int i = 0; i < n; i++){
			int temp1,temp2;
			cin >> temp1 >> temp2;
			red[temp1] = min(temp2 - 1, red[temp1]);
			if(temp2 == 0)
				mx = min(temp1, mx);
		}
		if(mx == 1e6 + 1){
			cout << "INF" << endl;
			continue;
		}
		int ans = red[0];
		for(int i = 1; i < mx; i++){
			red[i] = min(red[i],red[i - 1]);
			ans = max(ans, red[i] + i);
		}
		if(ans >= 0x3f3f3f3f)
			cout << "INF" << endl;
		else cout << ans << endl; 
	}
	return 0;
}
