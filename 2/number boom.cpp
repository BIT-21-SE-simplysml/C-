#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	cout << "Number:";
	cin >> n;
	for(int i; ; ){
		cout << "Please type your choice:";
		cin >> i;
		if (i == n){
			cout << "Boom!!!";
			break;
		}
		if (i > n) {
			cout << "Too Large" << "\n"; 
			continue;
		}
		cout << "Too Small" << "\n";
	}
	return 0;
}
