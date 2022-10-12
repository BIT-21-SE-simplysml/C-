#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
int R[MX];
int f[MX][30];
int lg[MX];
int E[MX];
int D[MX];
bool vis[MX];
vector<int> p[MX];
int tot;
#define cnt tot

void get_log(){
	lg[1] = 0;
	for(int i = 2; i < MX; i++){
		lg[i] = lg[i / 2] + 1;
	}
}

void rmq(){
	for(int i = 1; i <= cnt; i++){
		f[i][0] = R[i];
	}
	for(int j = 1; (1<<j)<=cnt; j++){
		for(int i = 1; i + (1<<(j-1)) <= cnt; ++i){
			if(D[f[i][j-1]] < D[f[i+(1<<(j-1))][j-1]]){
				f[i][j] = f[i][j - 1];
			}
			else f[i][j] = f[i+(1<<(j-1))][j-1];
		}
	}
	return;
}

void dfs(int x,int depth){
	vis[x] = true;
	tot++;
	E[tot] = x;
	D[tot] = depth;
	if(R[x] == 0){
		R[x] = cnt;
	}
	for(int i = 0; i < p[x].size(); i++){
		if(vis[p[x][i]]) continue;
		dfs(p[x][i],depth+1);
		tot++;
		E[cnt] = x;
		D[cnt] = depth;
		if(R[x] == 0){
			R[x] = cnt;
		}
	}
}

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i < n; i++){
		int x,y;
		cin >> x >> y;
		p[x].push_back(y);
		p[y].push_back(x);
	}
	dfs(1,0);
	rmq();
	int k;
	cin >> k;
	while(k--){
		int l,r;
		cin >> l >> r;
//		int l1; 
//		int r1;
//		l1 = l;r1 = r;
		l = R[l];
		r = R[r];
		if(l > r)swap(l,r);
		int temp = lg[r-l+1];
//		cout << l << ' ' << r << endl;
//		cout << "tp::" << temp << endl;
		int fa = ((D[f[l][temp]]<D[f[r-(1<<(temp))+1][temp]]) ? f[l][temp] : f[r-(1<<temp)+1][temp]);
		cout << D[r] - D[fa] + D[l] - D[fa] << endl;
//		cout << fa << endl;
	}
	return;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int t;
//	cin >> t;
	t = 1;
	get_log();
	while(t--){
		solve();
	}
	return 0;
}