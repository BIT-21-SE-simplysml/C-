#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
int a[1001];
int f[1001][10];
int lg[1001];
void get_log(){
	lg[1] = 0;
	for(int i = 2; i < 1001; i++){
		lg[i] = lg[i / 2] + 1;
	}
}
void rmq(int n){
	for(int i = 1; i <= n; i++){
		f[i][0] = a[i];
	}
	for(int j = 1; (1<<j)<=n; j++){
		for(int i = 1; i + (1<<(j-1)) <= n; ++i){
			f[i][j] = max(f[i][j - 1],f[i+(1<<(j - 1))][j - 1]);
		}
	}
	return;
}
void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	rmq(n);
	int k;
	cin >> k;
	while(k--){
		int l,r;
		cin >> l >> r;
		int temp = lg[r-l+1];
		cout << max(f[l][temp],f[r-(1<<(temp))+1][temp]) << endl;
	}
	return;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int t;
	cin >> t;
//	t = 1;
	get_log();
	while(t--){
		solve();
	}
	return 0;
}