#include <bits/stdc++.h>
using namespace std;
long long a[100002];
long long sum;
int n;
struct tr{
	int l,r;
	long long tot;
	long long mark;
}; 

tr dp[200002];

void pluss(int now, int left, int right, long long k){
	if(left > right)
		return;
	if(left == dp[now].l && right == dp[now].r){
		dp[now].mark += k;
		dp[now].tot += 1ll * k * (dp[now].r - dp[now].l + 1);
		return;
	}
	if(dp[now].mark != 0){
		dp[now * 2].mark += dp[now].mark;
		dp[now * 2 + 1].mark += dp[now].mark;
		dp[now * 2 + 1].tot += (dp[now * 2 + 1].r - dp[now * 2 + 1].l + 1) * dp[now].mark;
		dp[now * 2].tot += (dp[now * 2].r - dp[now * 2].l + 1) * dp[now].mark;
		dp[now].mark = 0; 
	}
	int mid = (dp[now].l + dp[now].r) / 2;
	if(right <= mid)
		pluss(now * 2, left, right, k);
	else if(left > mid)
		pluss(now * 2 + 1, left, right, k);
	else{
		pluss(now * 2, left, mid, k);
		pluss(now * 2 + 1, mid + 1, right, k);
	}
	dp[now].tot = dp[now * 2].tot + dp[now * 2 + 1].tot;
	return;
}

void search(int now, int left, int right){
	if(left > right)
		return;
	if(dp[now].l == left && dp[now].r == right){
		sum += dp[now].tot;
		return;
	}
	if(dp[now].mark != 0){
		dp[now * 2].mark += dp[now].mark;
		dp[now * 2 + 1].mark += dp[now].mark;
		dp[now * 2 + 1].tot += (dp[now * 2 + 1].r - dp[now * 2 + 1].l + 1) * dp[now].mark;
		dp[now * 2].tot += (dp[now * 2].r - dp[now * 2].l + 1) * dp[now].mark;
		dp[now].mark = 0; 
	}
	int mid = (dp[now].l + dp[now].r) / 2;
	if(right <= mid){
		search(now * 2, left, right);
	}
	else if(left > mid){
		search(now * 2 + 1, left, right);
	}
	else{
		search(now * 2, left, mid);
		search(now * 2 + 1, mid + 1, right);
	}
	return;
}

void build(int now, int left, int right){
	dp[now].l = left;
	dp[now].r = right;
	dp[now].mark = 0;
	if(left == right){
		dp[now].tot = a[left];
		return;
	}
	int mid = (left + right) / 2;
	build(now * 2, left, mid);
	build(now * 2 + 1, mid + 1, right);
	dp[now].tot = dp[now * 2].tot + dp[now * 2 + 1].tot;
	return;
}

int main(){
	int m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	for(int i = 1; i < 2 * n; i++){
		cout << dp[i].tot << ' ';
	}
	for(int i = 1; i <= m; i++){
		int choice;
		cin >> choice;
		if(choice == 1){
			int le,ri;
			long long k;
			cin >> le >> ri >> k;
			pluss(1,le,ri,k);
		}
		else{
			int le,ri;
			cin >> le >> ri;
			sum = 0;
			search(1,le,ri);
			cout << sum << endl;
		}
	}
	return 0;
}
