#include<bits/stdc++.h>
using namespace std;
struct edges{
	int a,b,c;
};
vector<edges> a[101];
edges edge[200005];
int r[5005];
int sum[101];
bool cmp(edges x,edges y){
    return x.a < y.a;
}

int find(int x){
	if(r[x] == x)
		return x;
	return r[x] = find(r[x]);
}

bool MST(int x){
	if(m - x + 1 < n - 1)
		return false;
	for(int i = 1; i <= n; i++)
		r[i] = i;
	int num = 0;
	for(int i = x; i <= m; i++){
		int p = find(edge[i].b);
		int q = find(edge[i].c);
		if(p == q)
			continue;
		++ num;
		r[p] = q;
	}
	if(num == n - 1)
		return true;
	return false;	
}

int main(){
	int n,m;
	cin >> n >> m;
	int temp = 0;
	edge[0].a = 0;
	for(int i = 1; i <= m; i++){
		scanf("%d", &edge[i].b);
		scanf("%d", &edge[i].c);
		scanf("%d", &edge[i].a);
	}
	sort(edge, edge + m, cmp);
	for(int i = 1; i <= n; ++i){
		if(edge[i].a != edge[i - 1].a)
			++temp;
		a[temp].push_back(edge[i]));
	}
	for(int i = 1; i <= n; i++){
		r[i] = i;
	}
	return 0;
}
