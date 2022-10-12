#include<bits/stdc++.h>
using namespace std;
long long a[31];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < 31; i++)
			a[i] = 0;
		for(int i = 0; i < n; i++){
			long long temp;
			scanf("%d", &temp);	
			int k = 0; 
			while(temp > 0){
				a[k]+=temp % 2;
				k++;
				temp /= 2;
			}
		}
		cout << "1 ";
		for(int k = 2; k <= n; k++){
			bool p = true;
	//		cout << k << endl;
			for(int i = 0; i < 31; i++){
				if(a[i] % k != 0)
					p = false;
			}
			if(p) 
				cout << k << ' ';
		}
		cout << endl;
	}
	return 0;
}
