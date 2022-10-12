// from https://codeforces.com/problemset/problem/1301/B
#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[100001];
long long k,mx,mn;

int main(){
	long long t;
	cin >> t;
	while(t--){
		cin >> n;
		mx = 0;mn = 0x3f3f3f3f;
		long long tot = 0;
		long long num = -0x3f3f3f3f;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			if(a[i] != -1){
				++tot;
				if(a[i] == num) -- tot;
				num = a[i];
			}
		}
		a[n + 1] = 0;
		if(tot == 0){
			cout << "0 42\n";
			continue;
		}
		if(tot == 1){
			cout << 0 << ' ' << num << endl;
			continue;
		}
		for(int i = 1; i <= n; i++){
			if((a[i + 1] == -1 || a[i - 1] == -1) && a[i] != -1){
				mx = max(mx, a[i]);
				mn = min(mn, a[i]);
			}
		}
		long long dis = 0;
		for(int i = 1; i <= n - 1; i++){
			if(a[i] == -1 && a[i + 1] == -1)
				continue;
			if(a[i] != -1 && a[i + 1] != -1){
				dis = max(dis,abs(a[i] - a[i + 1]));
			}
		} 
		cout << max(dis, (mx - mn + 1) / 2) << ' ' << (mx + mn) / 2 << endl;
	}	
}
//-1 2 0 -1 5 7

