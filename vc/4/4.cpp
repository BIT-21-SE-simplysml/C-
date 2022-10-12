#include <bits/stdc++.h>
using namespace std;
struct love{
	int own;
	int cute;
};
bool cmp(love x, love y){
	return x.own > y.own;
}

love b[100001];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> b[i].own;
		cin >> b[i].cute;
	}
	sort(b,b + n, cmp);
	love temp;
	temp.own = b[0].own;
	temp.cute = b[0].cute;
	for(int i = 1; i < n; i++){
		if(temp.own == b[i].own){
			temp.cute = min(temp.cute,b[i].cute);
			continue;
		}
		if(temp.cute < b[i].cute){
			cout << "yes" << endl;
			return 0;
		}
		if(b[i].cute < temp.cute){
			temp.cute = b[i].cute;
			temp.own = b[i].own;
		}
	}
	cout << "no" << endl;
	return 0;
}
