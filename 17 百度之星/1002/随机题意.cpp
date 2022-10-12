#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		priority_queue<long long> q;
		int n,k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			int m;
			cin >> m; 
			q.push(m);
		}
		long long u = 0;
		long long v = 0;
		u = q.top();
		q.pop();
//		cout << u;
		u = u + k; // max
		long long ans = 1;
		for(int i = 1; i < n; i++){
			long long temp = q.top();
			q.pop();
//			cout << "u=" << u << endl;
			if(u <= temp - k)
				continue;
			++ ans;
			cout << i << endl;
			if(u > temp + k)
				u = temp + k;
			else u--;
		}
		cout << ans << endl;
	}
}
