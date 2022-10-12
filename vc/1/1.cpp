#include <bits/stdc++.h>
using namespace std;
int a[1001];
int s[1001];
int main(){
	int m;
	cin >> m;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	} 
	sort(a,a + n);
	s[0] = a[0];
	if(s[0] > m){
		cout << 0 << endl;
		return 0;
	}
	for(int i = 1; i < n; i++){
		s[i] = s[i - 1] + a[i];
		if(s[i] > m){ 
			cout << i << endl;
			return 0;
		}
	}
	cout << n;
	return 0;
}
