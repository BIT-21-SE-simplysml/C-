#include<bits/stdc++.h> 
using namespace std;
bool p[400001];
int r[400001];

int find(int x){
	if(r[x] == x)
		return x;
	return r[x] = find(r[x]);
}

int main(){
	int n,m;
	for(int i = 0; i < 400001; i++)
		p[i] = false; 
	scanf("%d %d", &n, &m);
	vector<int> num;
	vector<int> edge[400001];
	for(int i = 0; i < m; i++){
		int temp1,temp2;
		scanf("%d %d", &temp1 , &temp2);
		edge[temp1].push_back(temp2);
		edge[temp2].push_back(temp1); 
	}
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		int temp;
		scanf("%d",&temp);
		p[temp] = true;
		num.push_back(temp); 
	}
	for(int i = 1; i <= n; i++){
		if(p[i] == false)
			num.push_back(i);
	}
	for(int i = 1; i <= n; i++)
		r[i] = i; 
	for(int i = 0; i < 400001; i++)
		p[i] = false;
	vector<int> ans;
	int tot = 0;
	for(int i = 1; i <= n; i++){
		int now = num.back();
		++ tot;
		num.pop_back();
		p[now] = true;
		int t = edge[now].size();
		for(int j = 0; j < t; j++){
			int x = edge[now][j];
			if(p[x]){
				int temp3,temp4;
				temp3 = find(now);
				temp4 = find(x);
				if(temp3 == temp4)
					continue;
                -- tot;
                //cout << tot << ' ' << temp1 <<  ' ' << temp2 << endl;
				r[temp3] = temp4;
			}
		}
	//	cout << tot << endl;
		if(i >= n - k)
			ans.push_back(tot);
	}
	int len = ans.size();
	for(int i = len - 1;i >= 0; i--){
		printf("%d\n",ans[i]);
	}
	return 0;
};
