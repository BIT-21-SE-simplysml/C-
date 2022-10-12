#include<bits/stdc++.h>
using namespace std;
const int MAX = 2 * 1e5 + 1;
 
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m,rb,cb,rd,cd;
		cin >> n >> m >> rb >> cb >> rd >> cd;
		int ans1,ans2;
		if(rb <= rd){
			ans1 = rd - rb;
		}
		else{
			ans1 = n - rd + n - rb;
		}
		if(cd >= cb)
			ans2 = cd - cb;
		else{
			ans2 = m - cd + m - cb; 
		}
		cout << min(ans1, ans2) << endl;
	}
	return 0;
}
