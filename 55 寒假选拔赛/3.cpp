#include<bits/stdc++.h>
using namespace std;
const int MAX = 2 * 1e5 + 2;
long long num[MAX];
long long peo[MAX];
long long s[MAX];

bool cmp(long long x, long long y){
    return x > y;
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int l,r,w;
        cin >> l >> r >> w;
        s[l] += w;
        s[r + 1] -= w;
    }
    for(int i = 1; i <= n; i++){
        num[i] = num[i - 1] + s[i];
    }
    sort(num + 1, num + n + 1, cmp);
    for(int i = 1; i <= n; i++){
        cin >> peo[i];
    }
    sort(peo + 1, peo + n + 1);
    long long ans = 0;
	for(int i = 1; i <= n ; i++){
  //      cout << peo[i] << ' ' << num[i] << ":1" << endl;
		ans += peo[i] * num[i];
    }
    cout << ans << endl;
}
