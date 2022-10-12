#include <bits/stdc++.h>
using namespace std;
int a1,a2,a3,b1,b2,b3;
int main(){
	cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
	if((a3 - a2) * (b2 - b1) == (a2 - a1) * (b3 - b2)) cout << "yes!";
	else cout << "no.";
 	return 0;	
}
