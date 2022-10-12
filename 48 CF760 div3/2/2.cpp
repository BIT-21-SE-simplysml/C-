#include<bits/stdc++.h>
using namespace std;
long long a[100];
long long b[100000];
int main(){
	int t;
	cin >> t;	
	while(t--){
		int n;
		cin >> n;
		if(n == 1){
			cin >> a[0];
			cout << a[0] << endl;
			continue;
		}
		long long gc0,gc1;
		cin >> a[0] >> a[1];
		gc1 = a[1]; gc0 = a[0];
		for(int i = 2; i < n; i++){
			cin >> a[i];
			if(i % 2 == 1)
				gc1 = __gcd(gc1 , a[i]);
			else gc0 = __gcd(gc0, a[i]);
		}
		bool p1 = true;
		for(int i = 0; i < n; i++,i++){
			if(a[i] % gc1 == 0)
				p1 = false;
		}
		if(p1){
			cout << gc1 << endl;
			continue;
		}
		bool p2 = true;
		for(int i = 1; i < n; i++,i++){
			if(a[i] % gc0 == 0)
				p2 = false;
		}
		if(p2)
			cout << gc0 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
