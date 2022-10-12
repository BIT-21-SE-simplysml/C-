#include<bits/stdc++.h>
using namespace std;
string s;
const int md = 1000000007;
int c[100005],h[100005],o[100005],k[100005],u[100005],d[100005],a[100005],i[100005];
int main(){
	cin >> s;
	int len = s.length();
	for(int j = 0; j < len; j++){
		c[j] = c[j - 1];
		if(s[j] == 'c')
			++c[j];
	}
	for(int j = 0; j < len; j++){
		h[j] = h[j - 1];
		if(s[j] == 'h')
			h[j] += c[j];
		h[j] %= md;
	}
	for(int j = 0; j < len; j++){
		o[j] = o[j - 1];
		if(s[j] == 'o')
			o[j] += h[j];
		o[j] %= md;
	}
	for(int j = 0; j < len; j++){
		k[j] = k[j - 1];
		if(s[j] == 'k')
			k[j] += o[j];
		k[j] %= md;
	}
	for(int j = 0; j < len; j++){
		u[j] = u[j - 1];
		if(s[j] == 'u')
			u[j] += k[j];
		u[j] %= md;
	}
	for(int j = 0; j < len; j++){
		d[j] = d[j - 1];
		if(s[j] == 'd')
			d[j] += u[j];
		d[j] %= md;
	}
	for(int j = 0; j < len; j++){
		a[j] = a[j - 1];
		if(s[j] == 'a')
			a[j] += d[j];
		a[j] %= md;
	}
	for(int j = 0; j < len; j++){
		i[j] = i[j - 1];
		if(s[j] == 'i')
			i[j] += a[j];
		i[j] %= md;
	}
	cout << i[len - 1];
}
