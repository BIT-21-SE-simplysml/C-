#include<bits/stdc++.h>
using namespace std;
bool p1,p2,p3,p4;
int main(){
	string s;
	getline(cin, s);
//	cout << s << endl;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'A') p1 = true;
		if(s[i] == 'B') p2 = true;
		if(s[i] == 'C') p3 = true;
		if(s[i] == 'D') p4 = true;
	}
	if(!p1)	cout << "Alice" << endl;
	if(!p2)	cout << "Bob" << endl;
	if(!p3)	cout << "Cindy" << endl;
	if(!p4)	cout << "Dani" << endl;
	return 0;
} 
