#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'

void solve(){
	int n;
	cin >> n;
	if(n == 3 || n == 1){
		cout << -1 << endl;
		return;
	}
	if(n == 5){
		cout << "5 4 1 2 3 \n";
		return;
	}
	if(n % 2 == 0){
		for(int i = n; i >= 1; i--){
			cout << i << ' ';
		}
		cout << endl;
		return;
	}
	for(int i = n; i > n / 2 + 1; i--){
		cout << i << ' ';
	}
	cout << n / 2 << ' ';
	cout << n / 2 + 1 << ' ';
	for(int i = n / 2 - 1; i >= 1; i--){
		cout << i << ' ';
	}
	cout << endl;
	return;
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