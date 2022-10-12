#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, a, x, y;
	cin >> n >> a >> x >> y;
	long long ans;
	if (n > a)
		ans = 1ll * a * x + (n - a) * y;
	else ans = 1ll * n * x; 
	cout << ans;
}
