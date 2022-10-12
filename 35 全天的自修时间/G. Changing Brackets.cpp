#include <bits/stdc++.h>
using namespace std;
string s;
int ans[1000002];
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> s;
		s = ' ' + s;
		int n = s.length() - 1;
		ans[0] = 0;
		for(int i = 1; i <= n; i++){
			ans[i] = ans[i - 1];
			if(s[i] == '[' || s[i] == ']'){
				if(i % 2 == 1){
					++ans[i];
				}
				else -- ans[i];
			}
		}
		int q;
		cin >> q;
		while(q--){
			int l,r;
			cin >> l >> r;
			printf("%d\n" ,abs(ans[r] - ans[l - 1]));
		}
	}
	return 0;
} 
