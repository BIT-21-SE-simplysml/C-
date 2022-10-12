#include<bits/stdc++.h> 
using namespace std;
int a[41];
int cnt[2000002]; 
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool pan = false;
		memset(a,0,41);
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			a[i] += 1000000;
		}
		for(int k = 2000001; k >= 1; k--){
			if(pan)
				break;
			int i = 0;
			for(; i < n; i++) {
				cnt[a[i] % k]++;
				if (cnt[a[i] % k] >= n / 2){
					pan = true;
					if(k == 2000001){
						printf("%d\n", -1);
						break;
					}
					printf("%d\n", k);
					break;
				}
			}
			if(i == n)
				-- i;
			for(int j = 0; j <= i; j++){
				cnt[a[j] % k]--;
			}
		}
	}
	return 0;
}
