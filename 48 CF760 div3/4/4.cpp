#include<bits/stdc++.h>
using namespace std;
int a[7];
int b[7];
int main(){
	int t;
	cin >> t;
	while(t--){
		for(int i = 0; i < 7; i++)
			cin >> b[i];
		sort(b, b + 7);
		cout << b[0] << ' ' << b[1] << ' ' << b[5] - b[1] << endl;
	}
	return 0;
}
