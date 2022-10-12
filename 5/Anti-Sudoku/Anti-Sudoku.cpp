#include <bits/stdc++.h>
using namespace std;
int a[10][10],b[10][10];
int	c[10];
bool spy = true; 
int find(int n,int m){
bool p;
	for (int i = 1; i <= 9; ++i)
		c[i] = 0;
	p = false;
	for (int i = 1; i <= 9; ++i)
		++c[b[n][i]];
	for (int i = 1; i <= 9; ++i)
		if(c[i] >= 2)
			p = true;
		if (p == false) return 0;
	p = false;
	for (int i = 1; i <= 9; ++i)
		c[i] = 0;
	for (int i = 1; i <= 9; ++i)
		++c[b[i][m]];
	for (int i = 1; i <= 9; ++i)
		if(c[i] >= 2)
			p = true;
		if(p == false)return 0;
	p = false;
	for (int i = 1; i <= 9; ++i)
		c[i] = 0;
	for (int i = (((n - 1) / 3) + 1); i <= (((n - 1) / 3) + 3); ++i){
		for(int j = (((m - 1) / 3) + 1);j <= (((m - 1) / 3) + 3); ++j)
			++c[b[i][j]];
		} 
	for (int i = 1; i <= 9; ++i)
		if(c[i] >= 2)
			p = true;
		if(p == false)return 0;
	return 1;
}

void tr(int n){
	if (n == 10){
		spy = false;
		for(int i = 1; i <= 9; ++i){
			for(int j = 1; j <= 9; ++j){ 
				cout << b[i][j];
				} 
			cout << endl; 
		}
		return;
	}
	for(int i = 1; i <= 9; ++i){
		if (spy == false)return;
		for(int j = 1; j <= 9; ++i){
			if (spy == false)return;
			if(a[n][i] == j)continue;
			b[n][i] = j;
			if (find(n,i))
			tr(n + 1);	
		}
		b[n][i] = a[n][i];
	}
}


int main(){
	int t;
	cin >> t;
	while (t--){
		for(int i = 1; i <= 9; ++i){
			cin >> a[i][0];
			for(int j = 9; j >= 1; --j){
				a[i][j] = a[i][0] % 10;
				a[i][0] /= 10;
				b[i][j] = a[i][j];
			}
		}
		tr(1);
	}
}
