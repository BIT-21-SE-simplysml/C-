#include<bits/stdc++.h> 
using namespace std;
#define int long long
int a[1000001];
int c[1000001];
int n; 
int lowbit(int p){
	return (p&-p);	
}
void change(int l, int r, int k){
	while(r > 0){
		c[r] += k;
		r -= lowbit(r); 
	}
	l--;
	while(l > 0){
		c[l] -= k;
		l -= lowbit(l);
	}
}

void find(int x){
	int ans = 0;
	int temp = x;
	while(x <= n){
		ans += c[x];
		x += lowbit(x); 
	}
	cout << ans + a[temp] << endl;
}

signed main(){
	std::ios::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	while(m--){
		int temp;
		cin >> temp;
		if(temp == 1){
			int x,y,k;
			cin >> x >> y >> k;
			change(x, y, k);
		}
		else{
			int x;
			cin >> x;
			find(x);
		}
	}
	return 0;
}
