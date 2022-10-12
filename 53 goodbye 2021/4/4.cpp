#include<bits/stdc++.h>
using namespace std;
const int MAX = 2 * 1e5 + 5;
long long a[5 * 1e4 + 1];
long long s[5 * 1e4 + 1];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		cin >> x;
		s[0] = 0;
		s[1] = a[1];
		for(int i = 2; i <= n; i++)
			s[i] = s[i - 1] + a[i];
		int l = 1;
		int r = 1;
		while(r <= n){
			r++;
			if(s[r] - s[l - 1] >= x * (r - l + 1))
				continue;
			double ave = x;
			for(int i = l; i <= r; i++){
				ave = x;
			}
		}
	}
	return 0;
} 
