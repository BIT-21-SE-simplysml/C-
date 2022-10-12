#include<bits/stdc++.h>
using namespace std;
 
const int N = 2 * 1e5 + 2; 
int a[N];
 
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int place = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			if(a[i] == n)
				place = i;
		}
		if(place > 2 && place < n - 1){
			cout << -1 << endl;
			continue;
		}
		if(place == 1 || place == n){
			for(int i = n - 1; i >= 1; i--)
				cout << a[i] << ' ';
			cout << a[n] << endl;
		}
	}
	return 0;
}
