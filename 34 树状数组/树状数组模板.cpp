#include<bits/stdc++.h> 
using namespace std;
#define int long long
int a[1000001];
int c[1000001];
int n;
 
int lowbit(int p){
	return (p&-p);	
}
void find(int l, int r){
	int ans = 0;
	while(r > 0){
		ans += c[r];
		r -= lowbit(r); 
	}
	l--;
	while(l > 0){
		ans -= c[l];
		l -= lowbit(l);
	}
	cout << ans << endl;
}

void change(int x, int k){
	while(x <= n){
		c[x] += k;
		x += lowbit(x); 
	}
}
void change1(int l, int r, int k){
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
signed main(){
	int m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		change(i,a[i]);
	}
	while(m--){
		int temp;
		cin >> temp;
		if(temp == 1){
			int l,r,k;
			cin >> l >> r >> k;
			change1(l, r, k);
		}
		else{
			int x,y;
			cin >> x >> y;
			find(x, y);
		}
	}
	return 0;
}
