#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	while(scanf("%lld", &n) == 1){
		int t = 0;
		while(n > 0){
			t++;
			n = n / 2;
		}
		printf("%d\n", t);
	}
	return 0;
} 
