#include<bits/stdc++.h>
using namespace std;
const int MAX = 2 * 1e5 + 1;
pair<int, int> p[1001];
int num[1001];
int ans[1001][3];
int main(){
	int t;
	cin >> t;
	while(t--){
		for(int i = 0; i < 1001; i++){
			num[i] = 0;
		}
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> p[i].first >> p[i].second;
			for(int j = p[i].first; j <= p[i].second; j++)
				++num[j];
		}
		for(int j = 1; j <= n; j++){
			int flag;		int mn = 0x3f3f3f3f;
			for(int i = 1; i <= n; i++){
	//			cout << num[i] << ' ';
				if(num[i] < mn && num[i] != 0){
					mn = num[i];
					flag = i;
				}
			}
	//		cout << endl;
			for(int i = 1; i <= n; i++){
				if(p[i].second >= flag && p[i].first <= flag){
					for(int k = p[i].first; k <= p[i].second; k++)
						-- num[k];
					ans[i][0] = p[i].first;
					ans[i][1] = p[i].second;
					ans[i][2] = flag;
					p[i].second = -1;
					p[i].first = -1;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << endl; 
		}
		cout << endl;
	}
	return 0;
}
