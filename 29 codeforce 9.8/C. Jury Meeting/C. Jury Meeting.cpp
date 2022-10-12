#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 998244353;

ll quick_power_mod(ll a,ll b,ll m)
{
	ll result = 1;
	ll base = a;
	while(b>0)
	{
		if(b&1==1)
		result=(result*base)%m;
		base=(base*base)%m;
		b>>=1;
	}
	return result;
}
ll comp(ll a,ll b,int p)
{
	if(a<b)return 0;
	if(a==b)return 1;
	if(b>a-b)b=a-b;
	ll ans=1,ca=1,cb=1;
	for(ll i=0;i<b;i++)
	{
		ca=(ca*(a-i))%p;
		cb=(cb*(b-i))%p;
	}
	ans=(ca*quick_power_mod(cb,p-2,p))%p;
	return ans;
}

ll lucas(ll n,ll m,ll p)
{
	ll ans=1;
	while(n&&m&&ans)
	{
		ans=(ans*comp(n%p,m%p,p))%p;
		n/=p;
		m/=p;
	}
	return ans;
}

long long power(long long base, long long exp)
{
	long long result = 1;
	while (exp)
	{
		if (exp & 0x01){
			result *= base;
		}
		base *= base;
		exp >>= 1;
	}
	return result;
}

long long cn2(ll n)
{
	long long x = ((1 << n) + 1);
	long long mask = ((1 << n) - 1); 
	return ((power(x, n) >> ((n >> 1) * n)) & mask);
}

long long factorial(ll n){
	long long temp;
	if(n == 0)
		return 1;
	if (n == 1)
		return 1;
	else if (n & 0x01 == 1)
		return (n * factorial(n - 1));
	else{
		temp = (factorial(n >> 1));
		return (cn2(n) * temp * temp) % md;
	}
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll a[200002];
		ll maxn = -0x3f3f3f3f;
		ll n;
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			maxn = max(maxn,a[i]);
		}
		int num_maxn = 0;
		int num_cmaxn = 0;
		int cmaxn = -0x3f3f3f3f;
		for(ll i = 0; i < n; i++){
			if(a[i] == maxn)
				++ num_maxn;
			if(a[i] == maxn - 1)
				++ num_cmaxn;
		} 
		if((num_cmaxn == 0) && (num_maxn != n)){
			cout << 0 << endl;
			continue;
		}
		if((num_cmaxn == 0)){
			long long result = factorial(n);
			cout << result << endl;
			continue;
		}
		if(num_maxn >= 2){
			long long result = factorial(n);
			cout << result << endl;
		}
		if(num_maxn == 1){
			long long result = factorial(n);
			result = result - ((factorial(n - num_maxn - num_cmaxn) * factorial(num_cmaxn))%md) * lucas(n,num_maxn + num_cmaxn,md) % md;
			cout << result << endl; 
		}
	}
} 
