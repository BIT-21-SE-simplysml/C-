#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm> 
using namespace std;
struct edges{
	int a,b,c;
};
int r[199];

bool cmp(edges x,edges y){
    return x.a < y.a;
}

int find(int x){
	if(r[x] == x)
		return x;
	return r[x] = find(r[x]);
}

int main(){
	int n,m;
	while(~scanf("%d", &n)){
		if(n == 0)
			break;
		scanf("%d", &m);
		edges edge[3001];
		for(int i = 1; i <= m; i++){
			scanf("%d", &edge[i].b);
			scanf("%d", &edge[i].c);
			scanf("%d", &edge[i].a);
		}
		sort(edge, edge + m, cmp);
		for(int i = 1; i <= n; i++){
			r[i] = i;
		}
//		int num = 0;
		int ans = 0;
		for(int i = 1; i <= m; i++){
			int p = find(edge[i].b);
			int q = find(edge[i].c);
			if(p == q){
				continue;
			}
//			++num;
			ans += edge[i].a;
			r[p] = q;
//			if(num >= n - 1){
//				break;
	//			cout << "yes";
//			}
		}
	//	if(num == n - 1)
			printf("%d\n", ans);
	//	else printf("-1\n");
	}
	return 0;
}
