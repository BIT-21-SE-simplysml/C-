#include<bits/stdc++.h>
using namespace std;
int t;
int a[100001];
int s[100001][2];
int main(){
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		s[0][0] = 0;
		s[0][1] = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			a[i] %= 2;
			s[i][1] = s[i - 1][1] + a[i]; 
			s[i][0] = s[i - 1][0] + 1 - a[i];
		}
		if(abs(s[n][0] - s[n][1]) > 1){
			cout << -1 << endl;
			continue;
		}
		int temp1 = 0;
		int temp2 = 0;
		for(int i = 1; i <= n; i++){
			if(s[i][1] - s[i - 1][1] > 0)
				temp1 += abs(s[i][1] - s[i][0]);
			else temp2 += abs(s[i][1] - s[i][0]);
		}
		if(s[n][1] == s[n][0]){
			cout << min(temp1,temp2) << endl;
		}
		if(s[n][1] < s[n][0])
			cout << temp1 << endl;
		if(s[n][0] < s[n][1])
			cout << temp2 << endl;
	}
	return 0;
}
