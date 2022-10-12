#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		vector<char> st;
		int n = s.length();
		st.push_back(s[0]);
		int tot = 0;
		for(int i = 1; i < n; i++){
			if(s[i] == s[i - 1])
				continue;
			st.push_back(s[i]);			
		}
		n = st.size();
		int temp = 0;
		int last = 0;
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(temp == 0){
				if((st[i] == '1')||(st[i] == '2')){
					continue;
				}
				else {
					temp++;
					ans ++;
					continue;
				}
			}
			if(st[i] == '1'){
				if(last == 2){
					last = 0;
					ans = min(ans,2);
					tot += ans;
					temp = 0;
					ans = 0; 
				}
				last = 1;
				continue;
			}
			if(st[i] == '2'){
				if(last == 1){
					last = 0;
					ans = min(ans,1);
					tot += ans;
					temp = 0;
					ans = 0; 
				}
				last = 2;
				continue;
			}
			++ ans;
//			cout << ans << ' ' << tot << endl; 
		}
		if(temp = 1){
			if(last = 1)
				tot += min(ans,2);
			else tot += min(ans,1);
		}
		cout << tot << endl;
	}
	return 0;
}
