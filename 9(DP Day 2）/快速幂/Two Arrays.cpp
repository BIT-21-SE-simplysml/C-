#include<bits/stdc++.h>
using namespace std;
long long temp[11][11][1001];
int main(){
	int n,m;
	cin >> m >> n;
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= m; ++j){
			if (i > j) 
				temp[i][j][1] = 0;
			else temp[i][j][1] = i + j - 1;
		}
	for(int i = 1; i <= m; ++i){
		for(int j = i; j <= m; ++j){
			for(int k = 2; k <= n; ++ k)
				for(int p = i; p >= 1; p--)
					for(int q = j; q >= 1; q--)
						 temp[i][j][k] += temp[p][q][k - 1];
		}
	}
	int tem = 0;
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= m; ++j)
			tem += temp[i][j][n];
	cout << tem; 
	return 0;
}
