#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		vector<int> red;
		vector<int> blue;
		red.clear();
		blue.clear();
		int n;
		cin >> n;
		int a[200001];
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);		
		}
		string s;
		cin >> s;
		for(int i = 0; i < n; i++){
			if(s[i] == 'B')
				blue.push_back(a[i]);
			else red.push_back(a[i]);
		}
		sort(blue.begin(),blue.end());
		sort(red.begin(),red.end());
		int b = blue.size();
		int r = red.size();
		int p = 1;
		for(int i = 0; i < b; i++){
			if(blue[i] < i + 1){
				cout << "NO" << endl;
				p = 0;
				break;
			}
		}
//		cout << b << ' ' << r << endl;
		if(p == 0)
			continue;
		for(int i = r - 1; i >= 0; i--){
			if(red[i] > b + i + 1){
				cout << "NO" << endl;
				p = 0;
				break;
			}
		}
		if(p == 0)
			continue;
		cout << "YES" << endl;
	}
	return 0;
} 
