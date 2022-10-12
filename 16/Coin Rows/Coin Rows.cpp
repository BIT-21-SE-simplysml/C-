#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n + 1][3];
		int s[n + 1][3];
		s[0][1] = 0;
		s[0][2] = 0;
		for(int i = 1;i <= n; i++){
			cin >> a[i][1];
			s[i][1] = a[i][1] + s[i - 1][1];
		}
		for(int i = 1;i <= n; i++){
			cin >> a[i][2];
			s[i][2] = a[i][2] + s[i - 1][2];
		}
		int mn = 0x3f3f3f3f;
		for(int i = 1; i <= n; i++){
			int temp1,temp2;
			temp1 = s[i - 1][2];
			temp2 = s[n][1] - s[i][1];
			int temp = max(temp1,temp2);
			mn = min(mn,temp);
		}
		cout << mn << endl;
	} 
} 
