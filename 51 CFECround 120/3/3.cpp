#include<bits/stdc++.h>
using namespace std;
const int M = 2 * 1e5 + 1;
long long a[M];
int n;
long long k;
long long s[M];

bool check(long long mid){
	long long gap = s[0] - k;
	//cout << gap << ' ' << mid << endl;
	for(int i = 0; i < n; i++){
		if(i > mid)
			break;
		long long temp = a[0] - mid + i;
		long long sum = s[n - i] - temp * i + mid - i;
		if(sum >= gap){
			//cout << i << endl;
			return true;
		}
	}
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		long long left = 0;
		long long right = 1e10;
		for(int i = 0; i < n; i++)
			cin >> a[i]; 
		sort(a, a + n);
		s[n] = 0;
		s[n - 1] = a[n - 1];
		for(int i = n - 2; i >= 0; i--){
			s[i] = s[i + 1] + a[i];
		}
	//	cout << s[0] << endl;
		while(left <= right){
			long long mid = (left + right) >> 1;
			if(check(mid)){
				right = mid - 1;
			}
			else left = mid + 1;
		}
		cout << left << endl;
	}
	return 0;
} 
