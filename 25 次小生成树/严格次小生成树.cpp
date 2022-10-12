#include<bits/stdc++.h>
using namespace std;
struct edges{
	int a,b,c; 
};
const long long minn = -0x3f3f3f3f3f3f3f3f; 
edges edge[300005];
vector<edges> ed[100002];
bool visited[100002]; 
int r[5005];
long long mn[100002][21];
long long maxn[100002][21];
long long dp[100002][21];
int deep[100002];
bool istree[300005];
int n, m;
long long value;

bool cmp(edges x,edges y){
    return x.a < y.a;
}

void dfs(int u, int f){
	if(visited[u])
		return;
	deep[u] = deep[f] + 1;
	dp[u][0] = f;
	mn[u][0] = minn;
	maxn[u][0] = ed[u].a;
	visited[u] = true;
	int nn = ed[u].size();
	for(int i = 0; i < nn; i++){
		int temp = ed[u].b;
		if (temp = u)
			temp = ed[u].c;
		dfs(temp, u);
	} 
}

void doubleplus(){
	for(int i = 1; i <= 20; ++i){
		for(int j = 1; j <= n; ++j){
			dp[j][i] = dp[dp[j][i - 1]][i - 1];
			maxn[j][i] = max(maxn[j][i - 1], maxn[dp[j][i - 1]][i - 1]);
			mn[j][i] = max(mn[j][i - 1], mini[dp[j][i - 1]][i - 1]);
			if(maxn[j][i - 1] > maxn[dp[j][i - 1]][i - 1])
				mn[j][i] = max(mn[j][i], maxn[dp[j][i - 1]][i - 1]);
            else if (maxn[j][i - 1] < maxn[dp[j][i - 1]][i - 1])
				mn[j][i] = max(mini[j][i], maxn[j][i - 1]);
		}
	}
}//±¶Ôö 
void find_MST(){
	value = 0;
	for(int i = 1; i <= m; i++){
		scanf("%d", &edge[i].b);
		scanf("%d", &edge[i].c);
		scanf("%d", &edge[i].a);
	}
	sort(edge, edge + m, cmp);
	for(int i = 1; i <= n; i++){
		r[i] = i;
	}
	int i = 1;
	int num = 0;
	for(int i = 1; i <= m; i++){
		int p = find(edge[i].b);
		int q = find(edge[i].c);
		if(p == q){
			continue;
		}
		value += edge[i].a;
		istree[i] = true;
		r[p] = q;
		++num;
		ed[edge[i].b].push_back(edge[i]);
		ed[edge[i].c].push_back(edge[i]);
		if(num >= n - 1){
			break;
		}
	}
} 

int LCA(int u, int v){
	if(deep[u] < deep[v]){
		int temp;
		temp = u;
		u = v;
		v = t;
	}
	int i;
	for(int i = 0; i <= 20; i++){
		if((1 << i) > deep[u]){
			break;
		}
	}
	i--;
	for(int j = i; j >= 0; j--){
		if(deep[u] >= deep[v] + (1 << j)){
			u = dp[u][j];
		}
	}
	if(u==v){
		return u;
	}
	for(int j = 20; j >= 0; j--){
		if(dp[u][j] != dp[v][j]){
			u = dp[u][j];
			v = dp[v][j];
		}
	}
	return dp[u][0];
}

int find(int x){
	if(r[x] == x)
		return x;
	return r[x] = find(r[x]);
}

long long findmax(int u,long long v,long long m){
	long long ans = minn;
	for(int i = 20; i >= 0; --i){
		if(deep[dp[u][i]] >= deep[v]){
			if(m != maxn[u][i])
				ans = max(ans,maxn[u][i]);
			else ans = max(ans,mn[u][i]);
			u = dp[u][i];
		}
	}
	return ans;
}

int main(){
	cin >> n >> m;
	find_MST();
	for(int i = 0; i <= n; i++)
		visited[i] = false;
	deep[1] = 1;
	dfs(1, -1);
	doubleplus();
	long long ans;
	ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= m; i++){
		if(istree[i])
			continue;
		int x = edge[i].b;
		int y = edge[i].c;
		long long z = edge[i].a;
		long long lca = LCA(x, y);
		long long maxxx = findmax(x,lca,z);
		long long maxy = findmax(x,lca,z);
		ans = min(ans, value - max(maxxx, maxy) + z);
	}
	cout << ans;
	return 0;
}
