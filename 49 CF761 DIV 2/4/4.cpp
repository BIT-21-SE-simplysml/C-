#include<bits/stdc++.h>
using namespace std;

const MAX = 5 * 1e5 + 1;
int query[MAX][3];
int r[MAX];
int num[MAX];
//int ans[MAX];

int find(int x){
	if(r[x] == x)
		return x;
	return r[x] = find(r[x]);
}

int main(){
	int q;
	cin >> q;
	for(int i = 0; i < MAX; i++){
		r[i] = i; 
//		ans[i] = i;
	}
	
	for(int i = 1; i <= q; i++){
		cin >> query[i][0];
		if(query[i][0] == 1){
			cin >> query[i][1]; 
		}
		else{
			cin >> query[i][1] >> query[i][2];
		}
	}
	int t = 1;
	for(int i = q; i >= 1; i--){
		if(query[i][0] == 1){
			int temp = find(query[i][1]);
//			ans[t] = num[temp];
			ans[t] = temp;
			t++;
		}
		if(query[i][0] == 2){
			int temp1 = find(query[i][1]);
			int temp2 = find(query[i][2]);
			if(temp1 == temp2)
				continue;
			r[temp1] = temp2;
		}
	}
	for(int i = t - 1; i >= 1; i++){
		cout << ans[i] << ' ';
	}
}
