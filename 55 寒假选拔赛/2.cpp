#include<bits/stdc++.h> 
using namespace std;
char c[102][102];
int cnt,mx;
int m,n,h;

void chai(int x, int y){
	if(c[x][y] == '_')
		return;
	c[x][y] = '_';
	for(int i = x - 1; i > 0; i--){
		if(c[i][y] == '_' || c[i][y] == '@')
			break;
		c[i][y] = '_';
		bool p1 = false;
		bool p2 = false;
		for(int j = 1; j < y; j++){
			if(c[i][j] == '@')
				p1 = true;
		}
		for(int j = y + 1; j <= n; j++)
			if(c[i][j] == '@')
				p2 = true;
		if(p1 && p2)
			c[i][y] = '*';
	}
	for(int i = x + 1; i <= m; i++){
		if(c[i][y] == '_' || c[i][y] == '@')
			break;
		c[i][y] = '_';
		bool p1 = false;
		bool p2 = false;
		for(int j = 1; j < y; j++){
			if(c[i][j] == '@')
				p1 = true;
		}
		for(int j = y + 1; j <= n; j++)
			if(c[i][j] == '@')
				p2 = true;
		if(p1 && p2)
			c[i][y] = '*';
	}
	for(int i = y - 1; i > 0; i--){
		if(c[x][i] == '_' || c[x][i] == '@')
			break;
		c[x][i] = '_';
		bool p1 = false;
		bool p2 = false;
		for(int j = 1; j < x; j++){
			if(c[j][i] == '@')
				p1 = true;
		}
		for(int j = x + 1; j <= n; j++)
			if(c[j][i] == '@')
				p2 = true;
		if(p1 && p2)
			c[x][i] = '*';
	}
	for(int i = y + 1; i <= n; i++){
		if(c[x][i] == '_' || c[x][i] == '@')
			break;
		c[x][i] = '_';
		bool p1 = false;
		bool p2 = false;
		for(int j = 1; j < x; j++){
			if(c[j][i] == '@')
				p1 = true;
		}
		for(int j = x + 1; j <= n; j++)
			if(c[j][i] == '@')
				p2 = true;
		if(p1 && p2)
			c[x][i] = '*';
	}
	cnt = 0;
	for(int i = 1;i <= m; i++){
		for(int j = 1; j <= n; j++){
		//	cout << c[i][j];
			if(c[i][j] != '_')
				++cnt;
		}
		//cout << endl;
	}
}

void build(int x, int y){
	c[x][y] = '@';
	int l = 0;
	int r = 0x3f3f3f3f; 
	for(int i = 1; i <= m; i++)
		if(c[i][y] == '@'){
			if(i < x)
				l = i;
			if(x < i)
				r = min(r, i);
		}
	if(l != 0){
	//	cnt += x - l - 1;
		for(int i = l + 1; i < x; i++){
			c[i][y] = 'x';
		}
	}
	if(r != 0x3f3f3f3f){
//		cnt += r - x - 1;
		for(int i = x + 1; i < r; i++){
			c[i][y] = 'x';
		}
	}
//	cout << "output: " << r << ' ' << l << endl;
	l = 0; r = 0x3f3f3f3f;
	for(int i = 1; i <= n + 1; i++)
		if(c[x][i] == '@'){
			if(i < y)
				l = i;
			if(y < i)
				r = min(r, i);
		}
	if(l != 0){
		for(int i = l + 1; i < y; i++){
			c[x][i] = 'x';
		}
	}
	if(r != 0x3f3f3f3f){
		for(int i = y + 1; i < r; i++){
			c[x][i] = 'x';
		}
	}
	cnt = 0;
	for(int i = 1;i <= m; i++){
		for(int j = 1; j <= n; j++){
			//cout << c[i][j];
			if(c[i][j] != '_')
				++cnt;
		}
	//	cout << endl;
	}
	mx = max(mx, cnt);
//	cout << "output: " << mx << ' ' << cnt << endl;
	return;
}

int main(){
	cin >> m >> n >> h;
	for(int i = 0; i <= 101; i++)
		for(int j = 0; j <= 101; j++)
			c[i][j] = '_';
	cnt = 0; 
	mx = 0;
	while(h--){
		int r,c,t;
		cin >> r >> c >> t;
		chai(r + 1, c + 1);
		if(t == 0)
			build(r + 1,c + 1);
	}
	cout << mx << endl;
	cout << cnt << endl;
	return 0;
} 
