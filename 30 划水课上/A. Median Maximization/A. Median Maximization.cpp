#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,s;
		cin >> n >> s;
		int temp = (n + 1) / 2 - 1;
		if(temp > 0)
			n -= temp;
		cout << s / n << endl; 
	} 
	return 0;
} 
