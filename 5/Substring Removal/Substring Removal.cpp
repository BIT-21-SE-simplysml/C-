#include <bits/stdc++.h>
using namespace std;
char s[200005];
const int MOD = 998244353;
int main(){
	int n;
	int k = 0;
	cin >> n;
	cin >> s;
	int i = 0;
	for(; i <= n - 1; i++)
		if(s[i] != s[0])
			break;
	int j = n - 1;
	for(; j >= 0; j--) 
		if (s[n - 1] != s[j])
			break;
	j = n - j - 1;
	if(s[n - 1] == s[0]){
		cout << ((1LL * (i + 1) * (j + 1)) % MOD);
	}
	else  cout << (i + j + 1) % MOD;
	return 0;
} 
