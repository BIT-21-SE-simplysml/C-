#include <bits/stdc++.h>
using namespace std;
long long gbs[101];
long long a[24];
long long gcdd(long long a, long long b){
	long long temp;
	while(b != 0){
		temp = a % b;
		a = b;
		b = temp;
	}
	return (a);
}
int main(){
	int t;
	cin >> t;
	gbs[0] = 1;
	gbs[1] = 2;
	gbs[2] = 6;
	for(long long i = 3; i <= 24; i++){
		long long temp = gbs[i - 1] * (i + 1);
		gbs[i] = temp / gcdd(gbs[i - 1], i + 1);
	}
	while(t--){
		int n;
		cin >> n;
		int trash;
		for(int i = 0 ; i < n; i ++){
			if(i < 24)
				scanf("%d", &a[i]);
			if(i >= 24)
				scanf("%d", &trash);
		}
		if(n > 24)
			n = 24;
		bool p = true;
		for(int i = 0 ; i < n;i++){
			if(a[i] % gbs[i + 1] == 0)
				p = false;
		}
		if(p == false)
			cout << "NO" << endl;
		if(p)
			cout << "YES" << endl;
	}
	return 0;
}
 
