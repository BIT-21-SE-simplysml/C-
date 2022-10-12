#include<bits/stdc++.h>
using namespace std;
const int dir[4][2] = {{0, 1}, {0, -1}, {1,0}, {-1, 0}};
 
vector<string> grid;
vector<vector<bool> > vis;
int n,m;
 
bool is_border(int a, int b){
	if(a >= n || b >= m || a < 0 || b < 0)
		return true;
	return false;
}
 
bool check(int x, int y){
	int tot = 0;
	for(int i = 0; i < 4; i++){
		int a = x + dir[i][0];
		int b = y + dir[i][1];
		if(is_border(a, b)){
			continue;
		}
		if(grid[a][b] == '.')
			++ tot;
	}
//	cout << x << ',' << y << ':' << tot << endl;
	if(tot > 1)
		return false;
	return true;
}
 
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		cin >> n >> m;
		int x,y;
		grid.clear();
		vis.clear();
		vector<bool> tem;
		for(int i = 0; i < m; i++){
			tem.push_back(false);
		}
		for(int i = 0; i < n; i++){
			string s;
			cin >> s;
			grid.push_back(s);
			vis.push_back(tem);
			for(int j = 0; j < m; j++){
				if(grid[i][j] == 'L'){
					x = i;
					y = j;
					vis[x][y] = true;
					break;
				}
			}
		}
		queue<pair<int,int> > q;
		q.push(make_pair(x, y));
		while(!q.empty()){
			pair<int, int> temp;
			temp = q.front();
			q.pop();
			for(int i = 0; i < 4; i++){
				int a = temp.first + dir[i][0];
				int b = temp.second + dir[i][1];
				if(!is_border(a, b) && grid[a][b] != '#' && grid[a][b] != '+'){
					if(vis[a][b] == false){
						if(check(a,b)){
							q.push(make_pair(a, b));
							grid[a][b] = '+';
						}
						vis[a][b] = true;
					}
				}
			}
		}
		for(int p = 0; p < 2; p++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					vis[i][j] = false;
				}
			}
			vis[x][y] = true;
			q.push(make_pair(x, y));
			while(!q.empty()){
				pair<int, int> temp;
				temp = q.front();
				q.pop();
				for(int i = 0; i < 4; i++){
					int a = temp.first + dir[i][0];
					int b = temp.second + dir[i][1];
					if(!is_border(a, b) && grid[a][b] != '#' && grid[a][b] != '+'){
						if(vis[a][b] == false){
							if(check(a,b)){
								q.push(make_pair(a, b));
								grid[a][b] = '+';
							}
							vis[a][b] = true;
						}
					}
				}
			}
		}
		for(int i = 0; i < n; i++){
			cout << grid[i] << endl;
		}
	}
	return 0;
}
