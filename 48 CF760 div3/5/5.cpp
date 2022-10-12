#include<bits/stdc++.h>
using namespace std;
long long a[40001];
long long ans[40001];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long sum = 0;
		for(int i = 0; i < n; i++){ 
			cin >> a[i];
			sum += 1ll * a[i];
		}
		sum =  sum / (n * (n + 1) / 2);
		if(sum < n){
			cout << "NO" << endl;
			continue;
		}
		if((a[n - 1] - a[0] + sum) % n != 0){
			cout << "NO" << endl;
			continue;
		}
		ans[0] = (a[n - 1] - a[0] + sum) / n; 
		if(ans[0] <= 0){
			cout << "NO" << endl;
			continue;				
		}
		for(int i = 0; i < n - 1; i++){
			if((a[i] - a[i + 1] + sum) % n != 0){
				cout << "NO" << endl;
				continue;
			}
			ans[i + 1] = (a[i] - a[i + 1] + sum) / n;
			if(ans[i] <= 0){
				cout << "NO" << endl;
				continue;				
			}
		}
		cout << "YES" << endl;
		for(int i = 0; i < n; i++){
			cout << ans[i] << ' ';
		} 
		cout << endl;
	}
	return 0;
}
