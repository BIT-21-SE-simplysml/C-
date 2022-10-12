#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		long long x,y;
		long long n;
		cin >> x >> y;
		if(x < y && y < 3 * x){
			cout << (x + y) / 2 << endl;
			continue;
		}
		if(x < y){
			int temp = y % x;
			n = y - x + (x - (temp + x) / 2);
			cout << n << endl;
		}
		if(x == y){
			cout << x << endl;
			continue;
		}
		if(x > y){
			n = 1ll * x * y + y;
			cout << n << endl;
			continue;
		}
	}
	return 0;
}
