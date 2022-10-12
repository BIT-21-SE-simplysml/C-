#include<bits/stdc++.h>
using namespace std;
int f[22][22];
bool zzy[22][22];
int go[8][2]={{2,1},{-2,1},{1,2},{-1,2},{2,-1},{-2,-1},{1,-2},{-1,-2}};
int main(){
	int n1,m1,n2,m2;
	cin >> n1 >> m1 >> n2 >> m2;
	for(int i = 0; i <= n1; i++){
		for(int j = 0; j <= m1; j++){
			zzy[i][j] = true;
		}
	}
	zzy[n2][m2] = false;
	for(int i = 0; i < 8; i++){
		int temp1,temp2;
		temp1 = n2 + go[i][0];
		temp2 = m2 + go[i][1]; 
		if((temp1 >= 0) && (temp2 >= 0) && (temp1 <= n1) && (temp2 <= m1))
			zzy[temp1][temp2] = false;
	}
	f[0][0] = 1;
	for(int i = 1; i <= n1; i++){
		if(zzy[i][0])
			f[i][0] = f[i - 1][0];
		else f[i][0] = 0;
	}
	for(int i = 1; i <= m1; i++){
		if(zzy[0][i])
			f[0][i] = f[0][i - 1];
		else f[0][i] = 0;
	}
	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= m1; j++){
			if(zzy[i][j])
				f[i][j] = f[i - 1][j] + f[i][j - 1];
			else f[i][j] = 0;
		}
	}
/*	for(int i = 0; i <= n1; i++){
		for(int j = 0; j <= m1; j++){
			cout << zzy[i][j] << ' ';
		}
		cout << endl;
	}*/ 
	cout << f[n1][m1] << endl;
	return 0;
} 
