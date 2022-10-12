#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int a,b;
		b = a = 0;
		int num[101];
		int temp = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '1')
				a++;
			else {
				b++;
			}
		}
		for(int i = 0; i < n; i++){
			if(s[i] == '2'){
				num[temp] = i;
				num[temp + b] = i;
				temp ++;
			}
		}
		if(b == 1){
			cout << "NO" << endl;
			continue;
		}
		if(b == 2){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		temp = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '1'){
				for(int j = 0; j < n; j++){
					if(i == j)
						cout << 'X';
					else cout << '=';
				}
				cout << endl;
			}
			else{
				temp ++;
				for(int j = 0; j < n; j++){
					if(i == j)
						cout << 'X';
					else if(j == num[temp])
						cout << '+';
					else if(j == num[(temp - 2 + b) % b])
						cout << '-';
					else cout << '='; 
				}
				cout << endl;
			}
		}
	}
	return 0;
}
