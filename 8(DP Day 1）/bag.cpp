#include<bits/stdc++.h>
using namespace std;
int mx = 0;
int w[1005];
int v[1005];
int n,mw;
void bag(int k, int nw, int nv){
	if((k > n) || (nw > mw)){
		if(nv > mx)mx = nv;
		return;
	}
	bag(k + 1, nw + w[k], nv + v[k]);
	bag(k + 1, nw, nv);
}

int main(){
	cin >> n;
	cin >> mw;
	for(int i = 1; i <= n; ++i){
		cin >> w[i];
	}
	for(int i = 1; i <= n; ++i){
		cin >> v[i];
	}
	bag(1,0,0);
	cout << mx;
	return 0;
}
