#include<bits/stdc++.h>
using namespace std;
struct edges{
	int v,b,c,d;
};
struct cmp{
	bool operator()(edges x,edges y){
		return x.d < y.d;
	}
};
int t,n,m;
edges a[10001];
int main(){
	cin >> t;
	while(t--){
		long long ans = 0;
		priority_queue<edges,vector<edges>,cmp> q;
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			cin >> a[i].v;
			a[i].b = 1;
			a[i].d = a[i].v / (a[i].b + 1);
		}
		for(int i = 0; i < n; i++){
			cin >> a[i].c;
			q.push(a[i]);
		}
		while(m > 0){
			edges temp = q.top();
			q.pop();
			if(temp.b >= temp.c)
				continue;
			m--;
			temp.b++;
			ans += temp.d;
			temp.d = temp.d - (temp.v / (temp.b + 1));
			q.push(temp);
		} 
		long long tot;
		for(int i = 0; i < n; i++){
			tot += a[i].v;
		}
		cout << tot - ans << endl;
	}
	return 0;
} 
