#include<bits/stdc++.h>
using namespace std;
long long n,k,t;
int main(){
	cin >> t;
	while(t--){
		cin >> n >> k;
		if(n == 1){
			cout << "No!" << endl;
			continue;
		}
		if(k == 2){
			cout << "No!" << endl;
			continue;
		}
		if(k % 2 == 0){
			if(k == n)
				cout << "Yes!" << endl;
			else 
				cout << "No!" << endl;
			continue;
		}
		cout << "Yes!" << endl;
	}
	return 0;
}
