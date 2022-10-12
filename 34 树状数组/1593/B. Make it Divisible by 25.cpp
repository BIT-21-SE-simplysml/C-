#include<bits/stdc++.h> 
using namespace std;
int a[20];
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.length();
		int ans = 0x3f3f3f3f;
		int temp = 0;
		int flag = 0;
		for(int i = n - 1; i >= 0; i--){
			if(s[i] != '0')
				++ temp;
			else ++ flag;
			if(flag == 2)
				break;
		}
		ans = min(ans, temp);
		flag = 0; temp = 0;
		for(int i = n - 1; i >= 0; i--){
			if(flag == 1 && s[i] != '2')
				++ temp;
			if(flag == 1 && s[i] == '2')
				++ flag;
			if(s[i] != '5' && flag == 0)
				++ temp;
			if(flag == 0 && s[i] == '5')
				++ flag;
			if(flag == 2)
				break;
		}
		ans = min(ans, temp);
		flag = 0; temp = 0;
		for(int i = n - 1; i >= 0; i--){
			if(flag == 1 && s[i] != '7')
				++ temp;
			if(flag == 1 && s[i] == '7')
				++ flag;
			if(s[i] != '5' && flag == 0)
				++ temp;
			if(flag == 0 && s[i] == '5')
				++ flag;
			if(flag == 2)
				break;
		}
		ans = min(ans, temp);
		flag = 0; temp = 0;
		for(int i = n - 1; i >= 0; i--){
			if(flag == 1 && s[i] != '5')
				++ temp;
			if(flag == 1 && s[i] == '5')
				++ flag;
			if(s[i] != '0' && flag == 0)
				++ temp;
			if(flag == 0 && s[i] == '0')
				++ flag;
			if(flag == 2)
				break;
		}
		ans = min(ans,temp);
		cout << ans << endl;
	}
	return 0;
}
