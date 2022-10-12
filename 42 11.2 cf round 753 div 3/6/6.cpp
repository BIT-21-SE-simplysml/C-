#include <bits/stdc++.h>
using namespace std;
char a[26];
int main(){
	int t;
	cin >> t;
	while(t--){
		for(int i = 0; i < 26; i++)
			cin >> a[i];
		string s;
		cin >> s;
		int n = s.length();
		int lastflag = 0;
		int ans = 0;
		while(a[lastflag] != s[0]){
			++lastflag;
		}
		for(int i = 1; i < n; i++){
			int flag = lastflag;
			while(a[flag] != s[i]){
				++flag;
				flag %= 26;
			}
	//		cout << ans << ' '; 
			ans += abs(lastflag - flag);
			lastflag = flag; 
		}
		cout << ans << endl;
	}
	return 0;
}
