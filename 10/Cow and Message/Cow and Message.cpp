#include<bits/stdc++.h>
using namespace std;
//char ch[10005];
long long ans[30];
long long tot[30][30];
int main(){
	string s;
	cin >> s;
	int n = s.length();
	long long omax = 0;
//	int flag = 0;
	for(int i = 0; i <= n - 1; ++i){
		ans[int(s[i]) - int('a') + 1]++;
		if(ans[int(s[i]) - int('a') + 1] > omax){
			omax = ans[int(s[i]) - int('a') + 1];
//			flag = int(s[i]) - int('a') + 1;
		}
	}
	long long tmax = 0;
	for(int i = n - 1; i >= 1; --i){
		--ans[int(s[i]) - int('a') + 1];
		for(int j = 1; j <= 26; ++j){
			tot[j][int(s[i] - 'a') + 1] += ans[j]; 
			if(tmax < tot[j][int(s[i] - 'a') + 1])
				tmax = tot[j][int(s[i] - 'a') + 1];
		}
	}
	cout << max(omax,tmax);
}
