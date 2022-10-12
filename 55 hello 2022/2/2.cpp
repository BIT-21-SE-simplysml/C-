#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long mx,mn,mxv,mnv;
		mx = 0;
		mn = 0x3f3f3f3f3f3f3f3f;
		long long sp1; long long sp2;
		bool p = false;
		long long sp = 0x3f3f3f3f3f3f3f3f;
		while(n--){
			long long l,r,c;
			cin >> l >> r >> c;
			if(l == mn){
				mnv = min(mnv, c);
			}
			if(l < mn){
				mn = l;
				mnv = c;
			}
			if(r == mx){
				mxv = min(mxv, c); 
			}
			if(r > mx){
				mx = r;
				mxv = c;
			}
			if(p){
				if(mx != sp2 || mn != sp1){
					p = false;
				}
			}
	//		cout << mxv << ' ' << mnv << endl;
			if(mx == r && mn == l){
				 if(p == false){
					sp = c;
				 }
				 else sp = min(sp, c);
				 p = true;
				 sp1 = l;
				 sp2 = r;
			}
			if(p)
				cout << min(sp, mxv + mnv) << endl;
			else 
				cout << mxv + mnv << endl;
		//	cout << sp1 << ' ' << sp2 << endl;
		}
	}
	return 0;
} 
