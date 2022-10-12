#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		if(n < 6) 
			cout << 15 << endl;
		else {
			if (n % 2 == 0)
				cout << (5 * n / 2) << endl;
			else cout << (5 * ((n + 1) / 2)) << endl;
		}
	}
	return 0;
} 
