#include <bits/stdc++.h>
using namespace std;
int main(){
	int temp = 0;
	for(int i = 1; i <= 100; i++){
		if((i / 2) % 2 == 0){
			temp += i;
		}
		else temp -= i;
		cout << i << ": " << temp << endl;
	}
} 
