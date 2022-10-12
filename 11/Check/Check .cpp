#include<bits/stdc++.h>
using namespace std;
string s;
int a[27];
int main(){
	cin >> s;
	int len = s.length();
	for(int i = 0; i < len; i++){
		a[s[i] - 'a' + 1]++;
	}
	int s = a[1];
	for(int i = 2; i <= 26; ++i){
		if((a[i] != s)&&(a[i] != 0)){
			cout << "false";
			return 0;
		}
	}
	cout << "true";
	return 0;
}
