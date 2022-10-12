#include<bits/stdc++.h>
using namespace std;
const int MAX = 2 * 1e5 + 5;
int a[501];

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < 501; i++)
			a[i] = -0x3f3f3f3f;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int step = 1; step <= n; step++){
				for(int j = step; j <= n; j += step){
					int temp = 0;
					double basic = 1.0 * (a[i + j] - a[i]) / (j / step);
					int k = 0;
					while(step * k + i < n){
						if(abs(1.0 * a[step * k + i] - a[i] - k * basic) < 1e-6)
							++ temp;
						++k;
					}
					ans = max(ans, temp);
				}
			}
		}
		cout << n - ans << endl;
	}
	return 0;
} 
