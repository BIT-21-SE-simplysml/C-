#include<bits/stdc++.h>
using namespace std;
int n,m;
struct edges{
	int a,b,c;
};
edges edge[500005];
edges ed[10002];
int r[10002];
int	sizer[10002];
bool cmp(edges x,edges y){
    return x.a < y.a;
}

bool cmp2(edges x, edges y){
	return x.a > y.a;
}

int find(int x){
	if(r[x] == x)
		return x;
	return r[x] = find(r[x]);
}

bool MST(int x){
	if(m - x + 1 < n - 1)
		return false;
	for(int i = 1; i <= n; i++)
		r[i] = i;
	int num = 0;
	for(int i = x; i <= m; i++){
		int p = find(edge[i].b);
		int q = find(edge[i].c);
		if(p == q)
			continue;
		++ num;
		r[p] = q;
	}
	if(num == n - 1)
		return true;
	return false;	
}


int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> edge[i].b >> edge[i].c >> edge[i].a;
	}
	sort(edge + 1, edge + m + 1, cmp);
	int left = 1;
	int right = m;
	int temp;
	while(left < right){
		int half = (left + right) / 2;
//		cout << half << endl;
		if(MST(half)){
			left = half + 1;
			temp = half;
		}
		else right = half;
//		cout << MST(half) << endl;                                                                                                           
	}
	
	for(int i = 1; i <= n; i++){
		r[i] = i;
		sizer[i] = 1;
	}
	long long num = 0;
	long long ans = 0;
	int temp2;
	for(int i = temp; i <= m; i++){
		int p = find(edge[i].b);
		int q = find(edge[i].c);
		if(p == q){
			continue;
		}
		r[p] = q;
		++num;
		ed[num].a = edge[i].a;
		ed[num].b = edge[i].b;
		ed[num].c = edge[i].c;
		if(num >= n - 1){
			break;
		}
	}
//	cout << "no problem\n";
	sort(ed + 1, ed + 1 + num,cmp2);
	for(int i = 1; i <= n; i++){
		r[i] = i;
		sizer[i] = 1;
	}
	num = 0;
	for(int i = 1; i <= n; i++){
		int p = find(ed[i].b);
		int q = find(ed[i].c);
		if(p == q){
			continue;
		}
		r[p] = q;
		++num;
		ans += 1ll * ed[i].a * sizer[p] * sizer[q];
		sizer[q] += sizer[p];
		if(num >= n - 1){
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
