#include <bits/stdc++.h>
using namespace std;
int t, a, b;
int main(){
	cin >> t;
	while(t--){
		cin >> a >> b;
		if((a == 0)&&(b == 0)){
			cout << 0 << endl;
			continue;
		}
		if(a == b){
			cout << 1 << endl;
			continue;
		}
		int temp1 = a % 2;
		int temp2 = b % 2;
		if(temp1 != temp2){
			cout << -1 << endl;
			continue;
		}
		cout << 2 << endl;
	}
	return 0;
} 
