#include<bits/stdc++.h>
using namespace std;
long long binary[31];
int a[100002];
int b[100002][31];
int ansa[31];
int ansb[31];
int n,m,t;
int main(){
	cin >> t;
	n = 0;
	m = 0;
	memset(a, 0, sizeof(a));
	binary[0] = 1;
	for(int i = 1; i < 31; i++){
		binary[i] = binary[i - 1] * 2;
	}
	for(int i = 0; i <= 100001; i++){
		for(int j = 0; j < 31; j++){
			b[i][j] = 0;
		}
	}
	while(t--){
		memset(a, 0, n + 1);
		for(int i = 0; i <= m; i++){
			for(int j = 0; j <= 31; j++){
				b[i][j] = 0;
			}
		}
		memset(ansa, 0, sizeof(ansa));
		memset(ansb, 0, sizeof(ansb));
		cin >> n >> m;
		long long temp;
		for(int i = 1; i <= n; i++){
			cin >> temp; 
			for(int j = 0; j <= 31; j++){
				if(binary[j] == temp){
					a[i] = j;
				}
			}
		}
		for(int i = 1; i <= m; i++){
			cin >> temp;
			for(int j = 31; j >= 0; j--){
				if(binary[j] <= temp){
					b[i][j] = 1;
//					cout << j << endl;
					temp -= binary[j];
				}
			}
		}
		for(int i = 1; i <= n; i++){
			++ ansa[a[i]];
		}
		for(int i = 1; i <= m; i++){
			for(int j = 0; j <= 31; j++){
				if(b[i][j] > 0)
					ansb[j]++;
			}
		}
		int t = 0;
		for(int i = 0; i < 31; i++){
			if(ansa[i] > 0)
				t = i;
		}
		for(int i = t; i < 31; i++){
			if(ansb[i] > 0)
				t = i;
		}
		for(int i = 0; i <= t; i++){
			if(ansa[i] <= ansb[i]){
				if(i == t)
					cout << "Yes" << endl;
				continue;
			}
			else{
				if(i == t)
					cout << "No" << endl;
				else{
					int temp2;
					temp2 = ansa[i] - ansb[i];
					ansa[i + 1] += (temp2 + 1) / 2;
				}
			}
		}
	}
	return 0;
}
