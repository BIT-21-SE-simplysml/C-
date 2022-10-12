#include <bits/stdc++.h>
using namespace std;
bool a[6][6];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp1, temp2;
		cin >> temp1 >> temp2;
		a[temp1][temp2] = true;
		a[temp2][temp1] = true;
	} 
	// find all good;
	for(int i = 1; i <= 5; i++){
		for(int j = i + 1; j <= 5; j++){
			for(int k = j + 1; k <= 5; k++){
				if(a[i][j] && a[i][k] && a[j][k]){
					cout << "Happy Doggos!" << endl;
					return 0;
				}
			}
		}
	}
	for(int i = 1; i <= 5; i++){
		for(int j = i + 1; j <= 5; j++){
			for(int k = j + 1; k <= 5; k++){
				if((!a[i][j]) && (!a[i][k]) && (!a[j][k])){
					cout << "Happy Doggos!" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Sad Doggos..." << endl;
	return 0; 
}
