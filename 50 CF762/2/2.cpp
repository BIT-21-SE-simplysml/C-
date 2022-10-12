#include<bits/stdc++.h>
using namespace std;

int main(){
	for(int n = 1; n <= 1e9; n++){
		long long ans = 1;
		long long i;
		for(i = 2; i <= int(sqrt(n)); i++){
			if(1ll * i * i <= n){
				++ans;
			}
			if(1ll * i * i * i <= n){
				++ans;
				if(pow(int(sqrt(pow(i,3))),2) == pow(i,3))
					-- ans;
			}
		}
		long long ans2 = 1;
		for(i = 2; i <= int(sqrt(n)); i++){
			if(1ll * i * i <= n){
				++ans2;
			}
			if(1ll * i * i * i <= n){
				++ans2;
				if(pow(int(sqrt(pow(i,3) + 0.5 )),2) == pow(i,3))
					-- ans2;
			}
		}
		if(ans != ans2){
			cout << n << endl;
		}
	}
	return 0;
}
