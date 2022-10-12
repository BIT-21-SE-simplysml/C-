#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	while (n > 0){
		--n;
		int m;
		cin >> m;
		if(m % 2 == 0){
			for(int i = m; i >= 1; --i)
				cout << i << ' '; 
		}
		else{
			int half = (m / 2);
			for(int i = half; i >= 1; --i)
				cout << (i + half + 1) << ' ';
			for(int i = half + 1; i <= m; ++i)
				cout << (i - half) << ' ';
		} 
		cout << endl;
	}
	return 0;
}
