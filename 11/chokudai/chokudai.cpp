#include<bits/stdc++.h>
using namespace std;
string s;
const int md = 1000000007;
int c[100005],h[100005],o[100005],k[100005],u[100005],d[100005],a[100005],i[100005];
int main(){
	cin >> s;
	int len = s.length();
	for(int j = 0; j < len; j++){
		if(s[j] == 'c'){
			c++;
		}
		if(s[j] == 'h'){
			cn = c;
			h++;
		}
		if(s[j] == 'o'){
			hn = h;
			o++;
		}
		if(s[j] == 'k'){
			on = o;
			k++;
		}	
		if(s[j] == 'u'){
			kn = k;
			u++;
		}
		if(s[j] == 'd'){
			un = u;
			d++;
		}
		if(s[j] == 'a'){
			dn = d;
			a++;
		}
		if(s[j] == 'i'){
			an = a;
			i++;
		}
	}
	in = i;
	cout << ans;
}
