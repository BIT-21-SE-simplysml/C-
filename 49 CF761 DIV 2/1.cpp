#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		int tot = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == 'N') ++ tot; 
		}
		if(tot == 1)
			cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
