#include <bits/stdc++.h>
using namespace std;
pair<int, int> stk[200001];
int t, n;
int main( ) {
	cin >> t; 
	while(t--){
		scanf("%d", &n);
		if(n % 3 == 0) printf("%d %d %d\n", n / 3, n / 3, n / 3);
		else{
			int top = 0, cnt = 0;
			int tn = n;
			for(int i = 2; i * i <= tn; i++){
				if(tn % i == 0){
					int cur = 0;
					while (tn % i == 0){
						tn /= i;
						++cnt;
						++cur;
					}
					stk[++top] = make_pair(i, cur);
				}
			}
			if (tn > 1){
				stk[++ top] = make_pair(tn, 1);
				++ cnt;
			}
			if (cnt == 1) 
				printf("%d %d %d\n", 1, n / 2, n / 2);
			else if (top == 1 && stk[top].first == 2) {
				printf("%d %d %d\n", n / 4, n / 4, n / 2);
			}
			else {
				long long ans = 0; 
				int idx = -1;
				for(int i = 1; i <= top; i ++){
					if (stk[i].first == 2 && stk[i].second == 1) 
						continue;
					int tmp;
					if(stk[i].first == 2)
						tmp = 3LL * (n / 4);
					else
						tmp = (2LL + stk[i].first / 2) * (n / stk[i].first);
					if (tmp > ans){
						ans = tmp;
						idx = stk[i].first;
					}
				}
				if(idx == 2)
					printf("%d %d %d\n", n / 4, n / 4, n / 2);
				else 
					printf("%d %d %d\n", n / idx, n / idx * (idx / 2), n / idx * (idx / 2));
			}
		}
	}
	return 0;
}

