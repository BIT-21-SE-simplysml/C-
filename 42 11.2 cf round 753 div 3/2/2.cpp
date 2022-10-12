#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		long long x,n;
		cin >> x >> n;
		long long temp;
		if(n % 4 == 1)
			temp = n;
		if(n % 4 == 2)
			temp = -1;
		if(n % 4 == 3)
			temp = - n - 1;
		if(n % 4 == 0)
			temp = 0;
//9		cout << "temp:" << temp << endl;
		if(x % 2 == 0){
			cout << x - temp << endl;
		}
		else{
			cout << x + temp << endl;
		}
	}
	return 0;
} 
