#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		scanf("%d", &n);
		cin.get();
		string s;
		string ans;
		getline(cin, s);
		n = s.size();
		bool p = false;
		int num = 0;
		char last_c = ' ';
		for(int i = 0; i < n; i++){
			num %= 3;
			if(num == 0 && s[i] == last_c){
				ans += s[i];
			}
			if(num == 0 && s[i] != last_c){
				if(ans != ""){
					ans += last_c;
					p = true;
				}
				ans += s[i];
			}
			if(num == 1)
				last_c = s[i];
			num++;
			if(i == n - 1)
				ans += s[i];
		}
		if(p == false)
			ans += 'a';
		cout << ans << endl;
	}
	return 0;
}
