#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 300001;

struct uni{
	ll v,at,mt;
};
int n, m, p;
uni a[MX];
int num[100001];

void push(int now, int l, int r){
	int mid = (l + r) >> 1;
	a[now * 2].v = a[now * 2].v * a[now].mt + a[now].at * (mid - l + 1); 
	a[now * 2].v %= p;
	a[now * 2 + 1].v = a[now * 2 + 1].v * a[now].mt + a[now].at * (r - mid);
	a[now * 2 + 1].v %= p;
	a[now * 2].mt = a[now * 2].mt * a[now].mt % p;
	a[now * 2 + 1].mt = a[now * 2 + 1].mt * a[now].mt % p;
	a[now * 2].at = a[now].at + a[now].mt * a[now * 2].at;
	a[now * 2 + 1].at = a[now].at + a[now].mt * a[now * 2 + 1].at;
	a[now * 2 + 1].at %= p;
	a[now * 2].at %= p;
	a[now].at = 0;
	a[now].mt = 1;
	return;
}

void build(int l, int r, int now){
	a[now].mt = 1;
	a[now].at = 0;
	if(l == r){
		a[now].v = num[l];
		a[now].v %= p;
		return;
	}
	int mid = (l + r) >> 1;
	build(1, mid, now * 2);
	build(mid + 1, r, now * 2 + 1);
	a[now].v = (a[now * 2].v + a[now * 2 + 1].v) % p;
	return;
}

void add(int now, int l, int r, int x, int y, int k){
	if(y < l || x > r)
		return;
	if(l >= x && r <= y){
		a[now].at += k;
		a[now].at %= p;
		a[now].v = (a[now].v + k * (r - l + 1)) % p;
		return;
	}
	push(now,l,r);
	int mid = (l + r) >> 1;
	add(now,l, mid, x, y, k);
	add(now,mid + 1, r, x, y, k);
	a[now].v += a[now * 2].v;
	a[now].v += a[now * 2 + 1].v;
	a[now].v %= p;
	return;
}

void pluss(int now, int l, int r, int x, int y, int k){
	if(y < l || x > r)
		return;
	if(l >= x && r <= y){
		a[now].at *= k;
		a[now].at %= p;
		a[now].mt *= k;
		a[now].mt %= p;
		a[now].v *= k;
		a[now].v %= p;
		return;
	}
	push(now,l,r);
	int mid = (l + r) >> 1;
	pluss(now,l, mid, x, y, k);
	pluss(now,mid + 1, r, x, y, k);
	a[now].v += a[now * 2].v;
	a[now].v += a[now * 2 + 1].v;
	a[now].v %= p;
	return;	
}

long long query(int now, int l, int r, int x, int y){
	if(y < l || x > r)
		return 0;
	if(l >= x && r <= y){
		return a[now].v;
	}
	int mid = (l + r) >> 1;
	push(now,l,r);
	return (query(now,l, mid, x, y) + query(now, mid + 1, r, x, y)) % p;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	cin >> n >> m >> p;
	for(int i = 1; i <= n; i++){
		cin >> num[i];
	}
	build(1, n, 1);
	for(int i = 1; i <= n * 2; i++)
		cout << a[i].v << ' ';
	cout << endl;
	int x,y,k;
	for(int i = 0; i < m; i++){
		int cho;
		cin >> cho;
		switch(cho){
			case 1:
				cin >> x >> y >> k;
				pluss(1, 1, n, x, y, k);
				break;
			case 2:
				cin >> x >> y >> k;
				add(1,1,n,x,y,k);
				break;
			case 3:
				cin >> x >> y;
				cout << query(1,1,n,x,y) << endl;
				break;
		}
	}
	return 0;
}