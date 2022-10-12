#include<bits/stdc++.h>
using namespace std;
int b[16005];
int f[16005];
vector <int>  l[16005];
void tree(int root, int father){
	f[root] = b[root];
	for(int i = 0; i < l[root].size(); i++){
		if(l[root][i] == father)
			continue;
		tree(l[root][i],root);
		if(f[l[root][i]] > 0)
			f[root] += f[l[root][i]];
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	for(int i = 1; i < n; i++){
		int temp1,temp2;
		cin >> temp1 >> temp2;
		l[temp1].push_back(temp2);
		l[temp2].push_back(temp1);
	}
	f[0] = 0;
	tree(1,0);
	int ans = -0x3f3f3f3f;
	for(int i = 1; i <= n; i++){
		ans = max(ans,f[i]);
	}
	cout << ans;
}
