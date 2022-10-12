#include<bits/stdc++.h>
using namespace std;
struct edges{
	int a,b,c;
};
edges edge[200005];
int r[200005];
bool cmp(edges x,edges y){
    return x.a < y.a;
}

int find(int x){
	if(r[x] == x)
		return x;
	return r[x] = find(r[x]);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m,k;
		cin >> n >> m >> k;
		for(int i = 1; i <= m; i++){
			scanf("%d", &edge[i].b);
			scanf("%d", &edge[i].c);
			scanf("%d", &edge[i].a);
		}
		sort(edge + 1, edge + m + 1, cmp);
		for(int i = 1; i <= n; i++){
			r[i] = i;
		}
		int num = 0;
		long long ans = 0;
/*		for(int i = 1; i <= m; i++){
			cout << edge[i].b << ' ';
			cout << edge[i].c << ' ';
			cout << edge[i].a << endl;
		}*/
		for(int i = 1; i <= m; i++){
			int p = find(edge[i].b);
			int q = find(edge[i].c);
			if(p == q){
				continue;
			}
			++ num;
			if(edge[i].a > k)
				ans += 1ll * edge[i].a - k;
			if(num >= n - 1){
				break;
			}
			r[p] = q;
		}
		if(ans == 0){
//			cout << "yes";
			ans = abs(k - edge[1].a);
			for(int i = 2; i <= m; i++){
				ans = min(ans, abs(1ll * edge[i].a - k));
//				cout << ans << ' ';
			}
		}
//		cout << endl;
		cout << ans << endl; 
	}
	return 0;
}
