#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int W,H,w,h;
		cin >> W >> H;
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> w >> h;
		if (((x2 - x1 + w) > W)&&((y2 - y1 + h) > H)){
			cout << -1 << endl;	
			continue;
		}
		if (((x2 + w <= W))||(w <= x1)||((y2 + h) <= H)||(h <= y1)){
			cout << "0.000000000" << endl;
			continue;
		}
		int temp1;
		int temp2;
		temp1 = min(w - x1,w - W + x2);
		temp2 = min(h - y1,h - H + y2);
		double mn; 
		if ((x2 - x1 + w) > W)
			mn = temp2;
		else if((y2 - y1 + h) > H)
				mn = temp1;
				else mn = min(temp1,temp2);
		printf("%.8f",mn);
		cout << endl;
	}
	return 0;
}
