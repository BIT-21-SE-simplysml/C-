#include<bits/stdc++.h>
using namespace std;
int ans[101];
int main(){
	int t;
	cin >> t; 
	while(t--){
		int n,a,b;
		cin >> n >> a >> b;
		if((n - b > n / 2) || (n - b == n / 2 && a != b + 1)){
			cout << -1 << endl;
			continue;
		}
		if((a > n / 2 + 1) || (a == n / 2 + 1 && b != a - 1)){
			cout << -1 << endl;
			continue;
		}
		ans[1] = a; ans[n / 2 + 1] = b;
		int temp = n;
		for(int i = 2; i <= n / 2; i++){
			if(temp == b)temp--;
			ans[i] = temp;
			temp--;
		}
		temp = 1;
		for(int i = n / 2 + 2; i <= n; i++){
			if(temp == a)temp++;
			ans[i] = temp;
			temp++;
		}
		for(int i = 1; i <= n; i++){
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
