#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		if(n % 2 == 1){
			cout << "NO" << endl;
			continue; 
		}
		bool p = true;
		for(int i = 0; i < n / 2; i++){
			if(s[i] != s[i + n / 2]){
				p = false;
				cout << "NO" << endl;
				break;
			}
		}
		if(p)
			cout << "YES" << endl;
	}
	return 0;
}
