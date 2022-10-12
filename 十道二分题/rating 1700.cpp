//https://codeforces.com/problemset/problem/778/A
#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200001];
string s1,s2;

bool check(int mid){
	string s = s1;
	for(int i = 1; i <= mid; i++){
		s[a[i]] = ' ';
	}
//	cout << s << endl;
	int i = 1; int j = 1;
	while(1){
		if(s2[i] == s[j]){
//			cout << i << ' ' << j << endl;
			++i;
		}
		++j;
//		cout << i << ' ' << j << endl;
		if(i >= m + 1) return false;
		if(j >= n + 1) return true; 
	}
}

int main(){
	cin >> s1 >> s2;
	n = s1.size();
 	m = s2.size();
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	s1 = ' ' + s1;
	s2 = ' ' + s2;
	int l = 0; int r = n;
	while(l <= r){
//		cout << l << ' ' << r << endl;
		int mid = (l + r) >> 1;
		if(check(mid)){
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << l - 1 << endl;
}
