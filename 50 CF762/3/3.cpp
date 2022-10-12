#include<bits/stdc++.h>
using namespace std;
string s1,s3;
int c[19]; 
int main(){
	int t;
	cin >> t;
	while(t--){
		long long a,s;
		cin >> a >> s;
		int x,y;
		bool p = true;
		long long ans = 0;
		int j = 18;
		while(s > 0){
			ans = 0;
			x = s % 10;
			y = a % 10;
			s /= 10;
			a /= 10;
//			cout << x << ' ' << y << endl;
			if(x - y >= 0){
				ans += x - y;
			//	cout << ans << endl;
			}
			else{
				int temp = s % 10;
				if(temp != 1){
					p = false;
					break;
				}
				s/= 10;
				ans += 10 + x - y;
			//	cout << ans << endl;
			}
			c[j] = ans;
			j--;
		}
			//cout << s  << ' ' << a << endl;
		if(p == false || a != 0)
			cout << -1 << endl;
		else {
			bool p = false;
			for(int i = j + 1; i < 19; i++){
				if(c[i] == 0 && p == false)
					continue;
				p = true;
				cout << c[i];
			}
			cout << endl;
		} 
	}
	return 0;
}
