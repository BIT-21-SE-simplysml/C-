//from https://codeforces.com/problemset/problem/706/B 
#include<bits/stdc++.h>
using namespace std;

int n;
int pr[100001];
int q; 
int m[100001];

bool check(int mid, int ans){
	if(pr[mid] > ans) return true;
	return false; 
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> pr[i];
	cin >> q;
	for(int i = 1; i <= q; i++)
		cin >> m[i];
	sort(pr + 1, pr + n + 1);
//	for(int i = 1; i <= n; i++)
//		cout << pr[i] << ' ';
//	cout << endl;
	for(int i = 1; i <= q; i++){
		int l = 1; int r = n;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(check(mid, m[i]))	r = mid - 1;
			else l = mid + 1;
		}
		cout << l - 1 << endl;
	}	
}
