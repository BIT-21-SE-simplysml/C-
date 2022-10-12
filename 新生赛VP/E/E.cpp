#include<bits/stdc++.h>
using namespace std;
char c[2003][1005];
int main(){
	string s;
	cin >> s;
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(i == 0){
			if(s[i] == '0'){
				c[n - 1][0] = '*';
				c[n - 1][1] = '*';
			}
			if(s[i] == '1'){
				c[n - 1][0] = '-';
				c[n - 1][1] = '-';
			}
			continue;
		}
		int a = n - 1 + i;
		int b = n - 1 - i;
		for(int j = 0; j < i + 2; j++){
			if(s[i] == '0'){
				c[a][j] = '*';
				c[b][j] = '*';
			}
			else {
				c[a][j] = '-';
				c[b][j] = '-';
			}
		}
		for(int j = a - 1; j >= b + 1; j--){
			if(s[i] == '0'){
				c[j][i + 1] = '*';
			}
			else c[j][i + 1] = '|';
		}
	}
	for(int i = 0; i < 2 * n - 1; i++){
		for(int j = 0; j < n + 1; j++){
			cout << c[i][j];
		}
		cout << endl;
	}
	return 0;
}
