#include<bits/stdc++.h>
#include <sstream>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string s1,s2;
		int n1,n2,p1,p2;
		cin >> n1 >> p1 >> n2 >> p2;
		stringstream ss1;
		stringstream ss2;
		ss1 << n1;
		ss2 << n2;
		ss1 >> s1;
		ss2 >> s2;  
		if(s1.size() + p1 > s2.size() + p2)
			cout << ">" << endl;
		if(s1.size() + p1 < s2.size() + p2)
			cout << "<" << endl;
		if(s1.size() + p1 == s2.size() + p2){
			int l1 = s1.size();
			int l2 = s2.size();
			if(l1 < l2){
				for(int i = 1; i <= l2 - l1; i++){
					s1 += "0";
				}
			}
			if(l1 > l2){
				for(int i = 1; i <= l1 - l2; i++){
					s2 += "0";
				}
			}
			if(s1 > s2)
				cout << ">" << endl;
			if(s1 < s2)
				cout << "<" << endl;
			if(s1 == s2)
				cout << "=" << endl; 
		}
	}
	return 0; 
}
