#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	int a[200005];
	vector<int> b,c;
	while(t--){
		b.clear();
		c.clear();
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		bool p = true;
		int x,y;
		for(int i = 0; i < n; i++){
			if(a[i] != a[n - i - 1]){
				p = false;
				x = a[i];
				y = a[n - i - 1];
				break;
			}
		}
		if(p){
			cout << "YES"<<endl;
			continue;
		}
		bool p1 = true;
		bool p2 = true;
		for(int i = 0; i < n; i++){
			if(a[i] != x)
				b.push_back(a[i]);
			if(a[i] != y)
				c.push_back(a[i]);
		}
		int n1 = b.size();
		int n2 = c.size();
		for(int i = 0; i < n1; i++){
			if(b[i] != b[n1 - i - 1]){
				p1 = false;
				break;
			}
		} 
		for(int i = 0; i < n2; i++){
			if(c[i] != c[n2 - i - 1]){
				p2 = false;
				break;
			}
		}
		if(p1 || p2)
			cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
} 
