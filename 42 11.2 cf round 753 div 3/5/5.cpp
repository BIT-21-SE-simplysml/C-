#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cout << "/*/*"*/;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		string s;
		cin >> s;
		int l = s.length();
		int ml,mr,md,mu;
		int x,y;
		bool p = false;
		ml = mr = md = mu = x = y = 0;
		for(int i = 0; i < l; i++){
			if(s[i] == 'L')
				--x;
			if(s[i] == 'R')
				++x;
			if(s[i] == 'D')
				--y;
			if(s[i] == 'U')
				++y;
			ml = max(ml,-x);
			mr = max(mr,x);
			md = max(md,y);
			mu = max(md,-y);
			if(ml + mr >= m){
				int x0,y0;
				if(s[i] == 'L')
					y0 = ml;
				else y0 = ml + 1;
				x0 = mu + 1;
				cout << x0 << ' ' << y0 << endl;
				p = true;
				break;
			}
			if(md + mu >= m){
				int x0,y0;
				if(s[i] == 'U')
					x0 = mu;
				else x0 = mu + 1;
				y0 = ml + 1;
				cout << x0 << ' ' << y0 << endl;
				p = true;
				break;

			}
		}
		if(p == false)
			cout << mu + 1 << ' ' << ml + 1 << endl;
	}
	return 0;
} 
