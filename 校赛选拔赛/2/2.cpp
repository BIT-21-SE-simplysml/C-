#include<bits/stdc++.h>
using namespace std;
int a[305][305];
int main(){
	int n; 
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	int mx = -1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 1; k < n; k++){
				if(k + i >= n || k + j >= n)
					break;
				int pt1 = a[i][j]; 
				int pt2 = a[i + k][j + k];
				int pt3 = a[i + k][j];
				int pt4 = a[i][j + k];
				if((pt1 == pt2 && pt2 == pt3) && pt1 < pt4)
					mx = max(mx, pt1);
				if((pt2 == pt3 && pt3 == pt4) && pt2 < pt1)
					mx = max(mx, pt2);
				if((pt3 == pt4 && pt4 == pt1) && pt3 < pt2)
					mx = max(mx, pt3);
				if((pt4 == pt1 && pt1 == pt2) && pt4 < pt3)
					mx = max(mx, pt4);
//				cout << i << ' ' << j << ':' << pt1 << ' ' << pt2 << ' ' << pt3 << ' ' << pt4 << endl;
			}
		}
	}
	cout << mx << endl;
	return 0;
} 
