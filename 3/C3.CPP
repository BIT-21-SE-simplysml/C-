#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[11];
	int n;
	int b[10][10];
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i]; 
	sort(a, a + 10);
	for(int i = n-1; i >= 0; --i)
		cout << a[i] << ' ';
	return 0;
}
