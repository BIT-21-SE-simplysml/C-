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
		if(n == 1)
			cout << 1 << endl;
		if(place >= 2 && place <= n - 1){
			cout << -1 << endl;
			continue;	
		}
		if(place == n){
			for(int i = n - 1; i >= 1; i--)
				cout << a[i] << ' ';
			cout << a[n] << endl;
		}
		if(place == 1){
			cout << a[1] << ' ';
			for(int i = n; i > 2; i--){
				cout << a[i] << ' ';
			}
			cout << a[2] << endl;
		}
	}
	return 0;
}
