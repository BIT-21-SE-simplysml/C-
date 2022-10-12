#include <bits/stdc++.h>
using namespace std;
char c[100005];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> c[i];
		if(c[i] == '0')
			continue;
		if ((c[i] == '1') && (i % 2 == 1)){
			cout << "Takahashi";
			break;
		}
			cout << "Aoki";
			break;
	}
}
