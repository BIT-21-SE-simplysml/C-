#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		int n;
		cin >> n;
		cin >> s;
		bool p = false;
		for(int i = 0; i < n - 1; i++){
			if((s[i] == 'a') && (s[i + 1] == 'b')&&(p == false)){
				cout << i + 1 << ' ' << i + 2 << endl;
				p = true;
				break;
			}
			if((s[i] == 'b') && (s[i + 1] == 'a')&&(p == false)){
				cout << i + 1 << ' ' << i + 2 << endl;
				p = true;
				break;
			}
		}
		if(p == false)
			cout << -1 << ' ' << -1 << endl;
	}
	return 0;
}
