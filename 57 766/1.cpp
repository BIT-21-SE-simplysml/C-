#include<bits/stdc++.h>
using namespace std;
struct ed{
	int num;
	int next;
};
int sum[100001];
bool p[100001];
int ans[100001];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++){
			sum[i] = 0;
			p[i] = false;
		}
		ed temp1,temp2;
		vector<ed> e[n];
		for(int i = 1; i < n; i++){
			cin >> temp1.next >> temp2.next;
			temp1.num = i;
			temp2.num = i; 
			e[temp1.next].push_back(temp2);
			e[temp2.next].push_back(temp1);
			sum[temp1.next]++;
			sum[temp2.next]++; 
		}
		int tag = 0;
		for(int i = 1; i <= n; i++){
			if(sum[i] == 1)
				++ tag;
		}
		if(tag != 2){
			cout << -1 << endl;
			continue;
		}
		queue<int> q;
		q.push(e[1][0].next);
		q.push(1);
		p[1] = false;
		p[e[1][0].next] = false;
		ans[e[1][0].num] = 2;
		while(!q.empty()){
			int temp = q.front();
			q.pop();
			for(int i = 0; i < e[temp].size(); i++){
				if(!p[e[temp][i].next]){
					p[e[temp][i].next]= true;
					q.push(e[temp][i].next);
					ans[e[temp][i].num] = 5 - ans[temp];
				}
			}
		}
		for(int i = 1; i <= n; i++){
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
