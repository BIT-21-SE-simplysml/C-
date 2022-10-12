#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int x,y;
		cin >> x >> y;
		int mht = x + y;
		if(mht % 2 == 1){
			cout << "-1 -1" << endl;
			continue;
		}
		int ans = mht / 2;
		for(int i = 0; i <= 50; i++){
			int j = ans - i;
			if(j < 0)
				break;
			if(abs(x - i) + abs(j - y) == ans){
				cout << i << ' ' << j << endl;
				break;
			}
		}
	}
	return 0;
}
