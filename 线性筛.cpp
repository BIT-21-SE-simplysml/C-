#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 10000001;
int phi[MX];
int pri[MX];
int is_prime[MX];
int vis[MX];
void init(){
	int cnt = 0;
	for(int i = 2; i < MX; i++){
		if(!vis[i]){
			phi[i] = i - 1;
			pri[cnt++] = i;
			is_prime[i] = 1;
		}
		for(int j = 0; j < cnt;j++){
			if(1ll * pri[j] * i >= MX){
				break;
			}
			vis[i * pri[j]] = 0;
      		if(i % pri[j]){
        		phi[i * pri[j]] = phi[i] * (pri[j] - 1);			
			}
			else{
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			}
		}
	}
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	init();
}
