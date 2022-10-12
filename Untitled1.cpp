#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	ll te = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		te += (a[i] - 1);
	}
	if(te % 2 == 1){
		cout << "errorgorn\n";
	}
	else cout << "maomao90\n";
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int t;
	cin >> t;
//	t = 1;
	while(t--){
		solve();
	}
	return 0;
}