#include<bits/stdc++.h>
using namespace std; 

long long n, k;
long long a[200005];

bool check(long long mid){
	if(a[mid] > a[n / 2 + 1]) return true;
	return false;
}

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(n == 1){
		cout << a[1] + k; 
		return 0;	
	}
	sort(a + 1, a + n + 1);
	long long l = n / 2 + 1;
	long long r = n;
	while(1){
		while(l <= r){ 
			long long mid = (1ll * l + r) >> 1;
			if(check(mid)){
				r = mid - 1;
			}
			else l = mid + 1;
		}//l - 1 is who plus than mid;
		long long sum = l - 1 - n / 2;
//		cout << l - 1 << ' ' << k << endl;
		if(l == n + 1){
			cout << (k / sum) + a[n / 2 + 1];
			break;
		}
		k -= (a[l] - a[n / 2 + 1]) * sum;
		if(k <= 0){
			k += (a[l] - a[n / 2 + 1]) * sum;
			cout << (k / sum) + a[n / 2 + 1];
			break;
		}
		a[n / 2 + 1] = a[l];
		r = n;
	}
}
