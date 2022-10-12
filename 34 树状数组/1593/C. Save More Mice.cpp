#include<bits/stdc++.h> 
using namespace std;
int x[400001];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		for(int i = 0; i < k; i++){
			int temp;
			cin >> temp;
			x[i] = n - temp;
		} 
		sort(x,x + k);
		int ans = 0;
		int tot = 0;
		for(int i = 0; i < k; i++){
			if(ans > n){
				break;
			}
			if(ans < n - x[i]){
				ans += x[i];
				++ tot;
			}
		}
		cout << tot << endl;
	}
	return 0;
}
