#include<bits/stdc++.h>
using namespace std;

long long dp[2003];
long long ans[1003];

int main(){
	int t;
	cin >> t;
	while(t--){
		long long n,k,x;
		cin >> n >> k >> x;
		string s1;
		cin >> s1;
		int p = 0;
		for(int i = 0; i < 2003; i++)
			dp[i] = 0;
		for(int i = 0; i < 1003; i++){
			ans[i] = 0;
		}
		for(int i = 0; i < n; i++){
			if(dp[p] != 0 && s1[i] == 'a')
				++ p;
			if(s1[i] == '*')
				dp[p] += k; 
		}
		if(dp[p] == 0)
			p--;
		if(p < 0){
			string s2;
			for(int i = 0; i < n; i++)
				if(s1[i] == 'a'){
					s2 += 'a';
				}
			cout << s2 << endl;
			continue;
		}
		x--;
		for(int i = p; i >= 0; p--){
			ans[p] = x % (dp[p] + 1);
			x /= (dp[p] + 1);
			if(x == 0)
				break;
		}
//		for(int i = 0; i <= p; i++)
//			cout << ans[p] << ' ';
		string s2;
		long long kk = 0;
		s1 += 'a';
		if(s1[0] == 'a')
			s2 += 'a';
		for(int i = 1; i <= n; i++){
			if(s1[i] == 'a' && s1[i - 1] == '*'){		
				for(int j = 0; j < ans[kk]; j++){
					s2 += 'b';
				}
				kk++;
			}
			if(s1[i] == 'a' && i != n){
				s2 += 'a';
			}
		}
		cout <<s2 << endl;
	}
	return 0;
}
