#include<bits/stdc++.h>
using namespace std;
const int MAX = 2 * 1e5 + 5;
char c[MAX];
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		int n;
		cin >> n;
		cin >> s;
		char mn = s[0];
		int ans = 1;
		c[0] = mn;
		for(int i = 1; i < n; i++){
			if(s[i] <= mn){
				++ans;
				mn = s[i];
				c[i] = s[i];
				continue;
			}
			break;
		}
		if(n > 1){
			if(c[1] == c[0])
				ans = 1;
		}
		for(int i = 0; i < ans; i++){
			c[2 * ans - i - 1] = c[i];
		}
		for(int i = 0; i < 2 * ans; i++){
			cout << c[i];
		}
		cout << endl;
	}
	return 0;
} 
