#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 10001000
using namespace std;
int phi[M],prime[1001001],tot;
int Phi(int x)
{
    int i,re=x;
    for(i=2;i*i<=x;i++)
        if(x%i==0)
        {
            re/=i;re*=i-1;
            while(x%i==0)
                x/=i;
        }
    if(x^1) re/=x,re*=x-1;
    return re;
}
long long quick_power(long long x, long long y) {
	long long sum = 1;
	for (; y; y >>= 1) {
		if (y & 1) sum = 1LL * sum * x % p;
		x = 1LL * x * x % p;
	}
	return sum;
}

int Solve(int p)
{
    if(p == 1) return 0;
    int temp = 0;
    while(~p&1) p >>= 1, ++temp;
    int phi_p = Phi(p);
    int re = Solve(phi_p);
    (re += phi_p - temp % phi_p) %= phi_p;
    re = quick_power(2,re)%p;
    return re<<temp;
}
int main()
{
    int T,p;
    for(cin>>T;T;T--)
    {
        scanf("%d",&p);
        printf("%d\n",Solve(p));
    }
    return 0;
}
