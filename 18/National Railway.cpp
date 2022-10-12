#include<bits/stdc++.h>
using namespace std;
long long min1[1002][1002];
long long min2[1002][1002];
long long min3[1002][1002];
long long min4[1002][1002];
int points[1002][1002];
int main(){
	int h,w,c;
	cin >> h >> w >> c;
	for(int i = 0; i <= h + 1; i++){
		for( int j = 0; j <= w + 1; j++){
			min1[i][j] = 0x3f3f3f3f3f3f3f3f;
			min2[i][j] = 0x3f3f3f3f3f3f3f3f;
			min3[i][j] = 0x3f3f3f3f3f3f3f3f;
			min4[i][j] = 0x3f3f3f3f3f3f3f3f;
		}
	}
	for(long long i = 1; i <= h; i++){
		for(long long j = 1; j <= w; j++){
			cin >> points[i][j];
			long long temp = min(min1[i - 1][j], min1[i][j - 1]);
			min1[i][j] = min(temp, 1ll * points[i][j] - i * c - j * c);
//			cout << min1[i][j] << ' ';
		}
//		cout << endl;
	}
	for(long long i = 1; i <= h; i++){
		for(long long j = w; j >= 1; j--){
			long long temp = min(min2[i - 1][j], min2[i][j + 1]);
			min2[i][j] = min(temp,1ll * points[i][j] - i * c + j * c);
		}
	}
	for(long long i = h; i >= 1; i--){
		for(long long j = 1; j <= w; j++){
			long long temp = min(min3[i + 1][j], min3[i][j - 1]);
			min3[i][j] = min(temp , 1ll * points[i][j] + i * c - j * c);
		}
	}
	for(long long i = h; i > 0; i--){
		for(long long j = w; j >= 1; j--){
			long long temp = min(min4[i + 1][j], min4[i][j + 1]);
			min4[i][j] = min(temp,1ll * points[i][j] + i * c + j * c);
//			cout << min4[i][j] << ' ';
		}
//		cout << endl;
	}
	long long mn = 0x3f3f3f3f3f3f3f3f;
	for(long long i = 1; i <= h; i++){
		for(long long j = 1; j <= w; j++){
			long long temp4 = min(min4[i + 1][j], min4[i][j + 1]) - i * c - j * c + points[i][j];
			long long temp3 = min(min4[i + 1][j], min4[i][j + 1]) - i * c + j * c + points[i][j];
			long long temp2 = min(min2[i - 1][j], min2[i][j + 1]) + i * c - j * c + points[i][j];
			long long temp1 = min(min1[i - 1][j], min1[i][j - 1]) + i * c + j * c + points[i][j];
			temp1 = min(temp1, temp2);
			temp3 = min(temp3, temp4);
			temp1 = min(temp1, temp3);
//			cout << temp1 << ' '; 
			mn = min(mn , temp1);
		}
//		cout << endl;
	}
	cout << mn;
	return 0;
}
