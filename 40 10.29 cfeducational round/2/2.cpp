#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.length();
		int t1 = 0;
		int t2 = 0;
		for(int i = 1; i < n; i++){
			if(s[i] == 'a' && s[i - 1] == 'b'){
				++t2;
			}
			if(s[i] == 'b' && s[i - 1] == 'a')
				++t1;
		}
//		cout << t1 << ' ' << t2 << endl;
		int dif = t1 - t2;
		if(dif == 0){
			cout << s << endl;
			continue;
		}
		if(s[n - 1] == 'a'){
			s[n - 1] = 'b';
			cout << s << endl;
			continue;
		}
		if(s[n - 1] == 'b'){
			s[n - 1] = 'a';
			cout << s << endl;
			continue;
		}
	}
	return 0;
}
