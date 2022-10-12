#include<bits/stdc++.h>
using namespace std;
int ans[200002][6];
int main(){
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    string st[6];
    st[0] = "abc";
    st[1] = "acb";
    st[2] = "bac";
    st[3] = "bca";
    st[4] = "cab";
    st[5] = "cba";
	for(int i = 0; i < 6; i++){
		for(int j = 1; j <= n; j++){
			if(st[i][(j - 1) % 3] != s[j - 1]){
				ans[j][i] = ans[j - 1][i] + 1;
			}
			else ans[j][i] = ans[j - 1][i];
//			cout << ans[j][i] << ' ';
		}
//	cout << endl;
    }
    while(m--){
		int a,b;
		cin >> a >> b;
		int ans1;  
		ans1 = 0x3f3f3f3f;
		for(int i = 0; i < 6; i++){
			int temp = ans[b][i] - ans[a - 1][i];
			ans1 = min(ans1, temp);
		}
		cout << ans1 << endl;
	}
    return 0;
}
