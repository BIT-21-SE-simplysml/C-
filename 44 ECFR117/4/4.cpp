#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		long long x,a,b;
		cin >> a >> b >> x;
		if(x > a && x > b){
			cout << "NO" << endl;
			continue;
		}
		bool p = false;
		if(a < b){
			long long c = a;
			a = b;
			b = c;
		} 
		while(1){
			if(x % b == a % b){
				cout << "YES" << endl;
				p = true;
				break;
			}
			if(a % b == 0){
				break;
			}
			a = a % b;
			if(a < b){
				long long c = a;
				a = b;
				b = c;
			}
			if(x > a){
				break;
			}
		}
		if(p == false){
			cout << "NO" << endl;
		}
	}
	return 0;
}
