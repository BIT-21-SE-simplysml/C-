#include<bits/stdc++.h>
using namespace std;
long long sum[100001];
void find_in_string(long long n, long long k){
    if(n == 0){
        string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
        printf("%c", s[k - 1]);
        return;
    }
    if(k <= 34){
        string s = "What are you doing while sending \"";
        printf("%c", s[k - 1]);
        return;
    }
    if(n > 53){
        long long temp = k - (n - 53) * 34;
        if(temp > 0)
            find_in_string(53,temp);
        else {
            temp = k / 34;
            find_in_string(n - temp,k - temp * 34);
        }
        return;
    }
    if(k <= 34 + sum[n - 1]){
        find_in_string(n - 1 , k - 34);
        return;
    }
    if(k <= 66 + sum[n - 1]){
        long long temp = k - sum[n - 1] - 34 - 1;
        string s = "\"? Are you busy? Will you send \"";
        printf("%c", s[temp]);
        return;
    }
    if(k <= 66 + 2 * sum[n - 1]){
        find_in_string(n - 1, k - 66 - sum[n - 1]);
        return;
    }
    if(k == 66 + 2 * sum[n - 1] + 1){
        printf("\"");
    }
    if(k == 66 + 2 * sum[n - 1] + 2){
        printf("?");
    }
    return;
}


int main(){
    int t;
 //   scanf("%d", &t);
    sum[0] = 75;
    for(int i = 1; i <= 53; i++){
        sum[i] = sum[i - 1] * 2 + 68;
    }
   // while(t--){
     //   long long n,k;
       // scanf("%lld %lld", &n , &k); 
//		if(sum[n] != 0 && k > sum[n]){
  //          printf(".");
    //    }
      //  find_in_string(n,k);
   // }
   // printf("\n");
    for(int i = 0; i < 53; i++){
		printf("%lld\n", sum[i]);
    }
	return 0;
}
