// from https://codeforces.com/problemset/problem/424/B
#include<bits/stdc++.h>
using namespace std; 

struct city{
	double dis;
	int people;	
};

bool cmp(city x,city y){
	return x.dis < y.dis;
}

int n, k;
city c[1001]; 
int s[1001];

bool check(int mid){
	if(s[mid] >= k) return true;
	else return false;
}

int main(){
	cin >> n >> k;
	k = 1e6 - k;
	for(int i = 1; i <= n; i++){
		int temp1,temp2;
		cin >> temp1 >> temp2 >> c[i].people;
		c[i].dis = sqrt(1.0 * temp1 * temp1 + temp2 * temp2);
	}
	sort(c + 1, c + n + 1, cmp);
	for(int i = 1; i <= n; i++)
		s[i] = s[i - 1] + c[i].people;
	if(s[n] < k){
		cout << -1 << endl;
		return 0;
	}
	int l = 1;int r = n;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid))	r = mid - 1;
		else l = mid + 1;
	}
	printf("%.8f", c[l].dis);
}
