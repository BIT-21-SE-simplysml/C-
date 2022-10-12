#include<bits/stdc++.h>
using namespace std;
int num[100];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, l;
		cin >> n >> l;
		for(int i = 0; i < 100; i++){
			num[i] = 0;
		}
		for(int i = 0; i < n; i++){
			int temp;
			cin >> temp;
			for(int j = 0; j < 100; j++){
		//		if(temp % 2 == 1)
		//			cout << j << endl;
				num[j] += temp % 2;
				temp /= 2;
				//cout << j << endl;
			}
		}
		long long ans = 0;
		for(int i = 0; i < 100; i++){
			if(num[i] >= (n + 1) / 2){
				ans += 1 << i;
			//	cout << i;
			}
			//else cout << 0;
		}
		//cout << endl;
		cout << ans << endl;
	}
	return 0;
}
