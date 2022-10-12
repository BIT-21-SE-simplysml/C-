#include<bits/stdc++.h> 
using namespace std;
int a[41];
int cnt[2000002]; 
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool pan = false;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			a[i] += 1000000;
		}
		for(int k = 2000001; k >= 1; k--){
			if(pan)
				break;
			for(int i = 0; i < n;i ++) 
				cnt[a[i] % k]++;
			for(int i = 0; i < n; i ++){
				if (cnt[a[i] % k] >= n / 2){
					pan = true;
					if(k == 2000001){
						cout << -1 << endl;
						break;
					}
					cout << k << endl;
					break;
				} 
			} 
			for(int i = 0; i < n; i++){
				cnt[a[i] % k]--;
			}
		}
	}
	return 0;
}
