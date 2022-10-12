#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		long long tot = 0;
		int n;
		cin >> n;
		string s1;
		string s2;
		cin >> s1;
		cin >> s2;
		s1 = " " + s1 + "  ";
		s2 = " " + s2 + "  ";
		bool p[100002];
		for(int i = 0; i < 100002; i++){
			p[i] = false;
		}
		for(int i = 1; i <= n; i++){
			if((s1[i] == '0')&&(s2[i] == '1'))
				tot += 2;
			if((s2[i] == '0')&&(s1[i] == '1'))
				tot += 2;
			if((s2[i] == '2')&&(s1[i] == '0'))
				tot++;
			if((s1[i] == '2')&&(s2[i] == '0'))
				tot++;
			if((s1[i] == '0')&&(s2[i] == '0')){
			//	cout << p[2] <<endl;
				if((s1[i - 1] == '1') && (s2[i - 1] == '1') && (p[i - 1] == false)){
					tot += 2;
					p[i - 1] = true;
		//			cout << "yes";
				}
				else if((s1[i + 1] == '1') && (s2[i + 1] == '1') && (p[i + 1] == false)){
						tot += 2;
						p[i + 1] = true;
					//	cout << "yes";
					}
					else tot++;
			}
		}
		cout << tot << endl;
	}
	return 0;
} 
