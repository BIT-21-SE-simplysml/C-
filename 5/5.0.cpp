#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v;
int main(){
	for(int i = 0; i < 5; ++i){
		int n,m;
		cin	>> n >> m;
		v.push_back(make_pair(n,m));
	}
	sort(v.begin(),v.end());
	for(int i = 0; i < 5; ++i)
		cout << v[i].first << v[i].second << endl; 
}
