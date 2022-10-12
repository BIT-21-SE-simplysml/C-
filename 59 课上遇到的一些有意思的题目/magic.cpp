#include<stdio.h>
#define ll long long
int main(){
	int n;
	while(scanf("%d", &n) == 1){
		int cnt = 0;
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				int k = n - i - j;
				if(k < 0)
					break;
				if(n - 2 * i + n - 2 * j + n - 2 * k == n && n - 2 * i >= 0 && n - 2 * j >= 0 && n - 2 * k >= 0){
					++cnt;
//					printf("%d %d %d\n", i, j, k);
				}
			}
		}
		printf("%d\n", cnt);
	}
}