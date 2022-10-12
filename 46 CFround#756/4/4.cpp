#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 2;
int x[N];
bool p[N];
vector<int> ed[N];
bool visited[N]; 
int ans[N];
int tot[N];
struct tr{
	int fa;
	vector<int> son;
};
tr tre[N];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			visited[i] = false;
			ans[i] = 0;
			tre[i].fa = 0;
			tre[i].son.clear();
			tot[i] = 0;
			ed[i].clear();
		}
		for(int i = 1; i <= k; i++){
			cin >> x[i];
		}
		for(int i = 1; i <= k; i++)
			tot[i] = 0x3f3f3f3f;
		for(int i = 1; i <= n - 1; i++){
			int a,b;
			cin >> a >> b;
			ed[a].push_back(b);
			ed[b].push_back(a);	
		}
		queue<int> q;
		q.push(1);
		visited[1] = true;
		tre[1].fa = -1;
		ans[1] = 0;
		while(!q.empty()){ 
			int temp = q.front();
			q.pop();
			int n = ed[temp].size();
			for(int i = 0; i < n; i++){
				if(ed[temp][i] != tre[temp].fa)
					tre[temp].son.push_back(ed[temp][i]);
			}
			for(int i = 0;i < n; i++){
				if(!visited[ed[temp][i]]){
					q.push(ed[temp][i]);
					tre[ed[temp][i]].fa = temp;
					visited[ed[temp][i]] = true;
				}
			}
			if(temp != 1)
			ans[temp] = ans[tre[temp].fa] + 1;
		}
		for(int i = 1; i <= k; i++){
			tot[i] = 0;
			k = x[i];
			while(tre[k].fa != -1){
				tot[tre[k].fa] = min(tot[k] + 1, tot[tre[k].fa]);
				k = tre[k].fa;
			}
		}
		int p = false;
		for(int i = 1; i <= n; i++){
			if(tre[i].son.size() == 0)
				cout << ans[i] << ' ' << tot[i] << "pan" << i << endl;
			if(tot[i] <= ans[i] && tre[i].son.empty()){
				cout << "YES" << endl;
				p = true;
				break;
			}
		}
		if (!p)cout << "NO" << endl;
//		for(int i = 1; i <= n; i++){
//			cout << "fa" << tre[i].fa << endl;
//			for(int j = 0; j < tre[i].son.size(); j++)
//			cout << "son" << tre[i].son[j] << endl;
//		}
	}
	return 0;
} 
