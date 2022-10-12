#include <bits/stdc++.h>
using namespace std;
int place[105];
int n;
int a[105];
void findmax(int left, int right){
	int max;
	int temp,k;
	if(left >= right)
		return ;
	max = a[left];
	temp = left;
	for(int k = left; k <= right; ++k){
		if(max < a[k]){
			max = a[k];
			temp = k;
		}
	}
	for(int k = left; k <= right; ++k){
		if(k != temp)
			place[k] += 1;
	}
	findmax(left, temp - 1);
	findmax(temp + 1, right);
	return ;
}

int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		for(int j = 1; j <= n; ++j)
			place[j] = 0;
		cin >> n;
		for(int j = 1; j <= n; ++j){
			cin >> a[j];
		}
		findmax(1, n);
		for(int j = 1; j <= n; ++j){
			cout << place[j] << ' ';
		}
	}
	return 0;
}

