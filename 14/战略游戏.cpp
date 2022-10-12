#include<bits/stdc++.h>
using namespace std;
vector<int>  line[1505];
int f[1505][2];
void tree(int root){
	if (line[root].size() == 0){
		f[root][0] = 0;
		f[root][1] = 1;
		return;
	}
	++f[root][1];
	int t = line[root].size();
	for(int i = 0; i < t; i++){
		tree(line[root][i]);
		f[root][0] += f[line[root][i]][1];
		f[root][1] += min(f[line[root][i]][1], f[line[root][i]][0]);
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int temp,k;
		cin >> temp >> k;
		for(int j = 1; j <= k; j++){
			int r;
			cin >> r;
			line[temp].push_back(r);
		}
	}
	tree(0);
	int mn = min(f[0][1], f[0][0]);
	cout << mn;
}
