#include<bits/stdc++.h>
using namespace std;

const int N = 1000001;

long long c[N];
int sum[N];
long long n,m;

struct qu{
	long long l,r,h;
};

int lowbit(int p){
	return (p&-p);	
}

bool cmp(qu x,qu y){
	return x.h < y.h;
}

bool cmp2(pair<long long,long long> x, pair<long long, long long> y){
	return x.second < y.second;
}

long long find(long long l, long long r){
	long long ans = 0;
	while(r > 0){
		ans += c[r];
		r -= lowbit(r); 
	}
	l--;
	while(l > 0){
		ans -= c[l];
		l -= lowbit(l);
	}
	return ans;
}

void change(long long x, long long k){
	while(x <= n){
		c[x] += k;
		x += lowbit(x); 
	}
}

long long find2(long long l, long long r){
	long long ans = 0;
	while(r > 0){
		ans += sum[r];
		r -= lowbit(r); 
	}
	l--;
	while(l > 0){
		ans -= sum[l];
		l -= lowbit(l);
	}
	return ans;
}

void change2(long long x, long long k){
	while(x <= n){
		sum[x] += k;
		x += lowbit(x); 
	}
}

int main(){
	cin >> n >> m;
	long long label[N]; 
	for(int i = 1; i <= n; i++){
		scanf("%lld", &label[i]);
	}
	int t = 0;
	pair<long long, long long> l[N];
	long long temp[N];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%lld",&temp[j]);
		}
		for(int j = 1; j <= m; j++){
            if(j == label[i])
                continue;
            t++;
			l[t] = make_pair(t, temp[j] - temp[label[i]]);
		}
	}
	qu query[200005];
	int q;
	cin >> q;
	for(int i = 1; i <= q; i++){
		scanf("%lld %lld %lld", &query[i].l,&query[i].r,&query[i].h);
	}
	long long ans[N];
	ans[0] = 0;
	for(int i = 1; i <= n * (m - 1); i++){
		ans[i] = max(l[i].second, 1ll * 0) + ans[i - 1];
    }
    for(int i = 1; i <= n; i++){
		if(l[i].second < 0)
			change(i , 1);
    }
	sort(query + 1,query + q + 1, cmp);
    sort(l + 1,l + n + 1, cmp2);
    t = 1;
	for(int i = 1; i <= q; i++){
		while(l[t].second + query[i].h <= 0 && t <= n){
			change(l[t].first,l[t].second);
			t++;
			change2(l[t].first, -1); 
		}
        long long ANS =  1ll * ans[query[i].r * (m - 1)] - ans[query[i].l * (m - 1) - 1] + 1ll * (n * (m - 1) - find2(query[i].l * (m - 1) + 1, query[i].r * (m - 1))) * query[i].h + find(query[i].l * (m - 1) + 1 , query[i].r * (m - 1));
	    cout << ans[query[i].r * (m - 1)] - ans[(query[i].l - 1)* (m - 1)] << endl;
    }
}
