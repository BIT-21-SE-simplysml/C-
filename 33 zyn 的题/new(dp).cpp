#include <bits/stdc++.h>
using namespace std;
double dp[21];
int flag[21];
int num[5];
const int year[5] = {1,2,3,5,8};
const double magnification[5] = {0.0063,0.0066,0.0069,0.0075,0.0084};
int main(){
	dp[0] = 2000.0;
	for(int i = 1; i <= 20; i++){
		for(int j = 0; j < 5; j++){
			if (i - year[j] >= 0){
				if(dp[i - year[j]] + 1.0 * dp[i - year[j]] * 12 * year[j] * magnification[j] > dp[i]){
					dp[i] = dp[i - year[j]] + 1.0 * dp[i - year[j]] * 12 * year[j] * magnification[j];
					flag[i] = j;
				}
			}
		}
	}
	int t = 20;
	while(t > 0){
		++ num[flag[t]];
		t -= year[flag[t]];
	}
	printf("%d %d %d %d %d\n", num[4], num[3], num[2], num[1], num[0]);
	printf("%f\n" , dp[20]);
}
