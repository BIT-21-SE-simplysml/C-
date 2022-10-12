#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	int tot = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 1)
			++ tot;
	}
	bool p = false;
	string s1;
	for(int i = 0; i < n; i++){
		if(s[i] == '0' && !p)
			continue;
		if(s[i] == '1')
			p = true;
		s1 += s[i];
	}
	cout << s1 << endl;
	n = s1.length();
	p = false;
	for(int i = n - 1; i >= 0; i--){
		cout << i << endl;
		if(s1[i] == '0' && !p)
			continue;
		if(s1[i] == '1'){
			n = i + 1; 
			break;	
		}
	}
	s = "";
	cout << n << endl;
	for(int i = 0; i < n; i++){
		s += s1[i];
	}
	cout << s;
	return 0;
}
