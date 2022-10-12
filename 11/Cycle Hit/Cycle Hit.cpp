#include<bits/stdc++.h>
using namespace std;
string s[5];
int main(){
	cin >> s[1] >> s[2] >> s[3] >> s[4];
	if ((s[1] == "H") || (s[2] == "H") || (s[3] == "H") || (s[4] == "H"))
		int a = 1;
	else {
		cout << "No";
		return 0;
	}
	if ((s[1] == "2B") || (s[2] == "2B") || (s[3] == "2B") || (s[4] == "2B"))
		int a = 1;
	else {
		cout << "No";
		return 0;
	}
	if ((s[1] == "HR") || (s[2] == "HR") || (s[3] == "HR") || (s[4] == "HR"))
		int a = 1;
	else {
		cout << "No";
		return 0;
	}
	if ((s[1] == "3B") || (s[2] == "3B") || (s[3] == "3B") || (s[4] == "3B"))
		int a = 1;
	else {
		cout << "No";
		return 0;
	}
	cout << "Yes";
	return 0;
}
