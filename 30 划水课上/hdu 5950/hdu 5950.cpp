#include <bits/stdc++.h>
using namespace std;
const long long md = 2147493647;
long long ans[7];

struct arra{
	long long arr[7][7];
};

arra c;
long long cc[7][7] = {{0,2,0,0,0,0,0},{1,1,0,0,0,0,0},{0,1,1,0,0,0,0},{0,0,4,1,0,0,0},{0,0,6,3,1,0,0},{0,0,4,3,2,1,0},{0,0,1,1,1,1,1}};

arra matrix_multiplication(arra x, arra y){
	arra temp;
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 7; j++){
			temp.arr[i][j] = 0;
		}
	}
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 7; j++){
			for(int p = 0; p < 7; p++){
				temp.arr[i][j] += 1ll * x.arr[i][p] * y.arr[p][j];
				temp.arr[i][j] %= md;
			}
		}
	}
	return temp;
}

arra quick_matrix_multiplication(int k){
	if (k == 1){
		return(c);
	}
	if((k % 2) == 0){
		arra tem;
		tem = quick_matrix_multiplication(k / 2);
		return matrix_multiplication(tem,tem);
	}
	else {
		return (matrix_multiplication(quick_matrix_multiplication(k - 1),c));
	}
}

int main(){
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 7; j++){
			c.arr[i][j] = cc[i][j];
		}
	}
	long long t;
	cin >> t;
	while(t--){
		long long a,b,n;
		cin >> n >> a >> b;
		if(n == 1){
			cout << a << endl;
			continue;
		}
		if(n == 2){
			cout << b << endl;
			continue;	
		}
		long long temp[7];
		temp[0] = a;
		temp[1] = b;
		temp[2] = 81;
		temp[3] = 27;
		temp[4] = 9;
		temp[5] = 3;
		temp[6] = 1;
		arra anss = quick_matrix_multiplication(n - 2);
		long long ans = 0;
		for(int i = 0; i < 7; i++){
			ans += 1ll * temp[i] * anss.arr[i][1];
			ans %= md;
		}
		cout << ans << endl;
	}
	return 0;
}
