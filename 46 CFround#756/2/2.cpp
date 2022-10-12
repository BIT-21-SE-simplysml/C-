#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		long long a,b;
		cin >> a >> b;
		if(a < b) swap(a,b);
		if(a > (3 * b)){
			cout << b << endl;
			continue;
		}
		cout << (a + b) / 4 << endl;
	}
	return 0;
} 
