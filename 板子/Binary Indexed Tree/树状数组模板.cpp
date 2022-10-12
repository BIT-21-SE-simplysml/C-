#include<bits/stdc++.h> 
using namespace std;
int a[500001];
int c[500001];
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

int main(){
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
			int x,k;
			cin >> x >> k;
			change(x, k);
		}
		else{
			int x,y;
			cin >> x >> y;
			find(x, y);
		}
	}
	return 0;
}
