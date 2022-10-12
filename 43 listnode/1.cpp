#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,l,a,b;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d %d %d",&n,&m,&l,&a,&b);
		if(m > n)
			m = n;
		double ans1 =(double (n * l) - double( m * l)) / a + double(m * l) / b;
		double ans = 1.0 * ans1 / n;
		printf("%.8lf\n",ans);
	}
	return 0;
}
