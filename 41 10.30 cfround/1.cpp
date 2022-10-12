#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int a[100001];
		int n;
		cin >> n;
		bool flag = false;
		for(int i = 0; i < n; i++){
			scanf("%d" , &a[i]);
		}
		for(int i = 1; i < n; i++){
			if(a[i] - a[i - 1] <= 0)
				flag = true;
		}
		if(flag){
			cout << "YES" << endl;
		}
		else{
			if(n % 2 == 0)
				cout << "YES" << endl;
			else cout << "NO" << endl; 
		}
	}
	return 0;
} 
