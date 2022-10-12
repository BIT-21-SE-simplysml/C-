#include<bits/stdc++.h>
using namespace std;

void dijkstra(int start) {
    priority_queue<pair<long long, int> > q;
    vector<pair<int, int> > G[nn];
    long long dist[nn];
    int pre[nn];   
    for (int i = 0; i < n; ++i) {
        dist[i] = INFLL;
		pre[i] = -1;
    }
    q.push(make_pair(0, start));
  	dist[start] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        long long d = -q.top().first;
       	q.pop();
       	if (d != dist[u]) continue;
        for (int i = 0; i < G[u].size(); ++i) {
           	pair<int, int> p = G[u][i];
           	int v = p.first, w = p.second;
            if (dist[u] + w < dist[v]) {
               	dist[v] = dist[u] + w;
               	q.push(make_pair(-dist[v], v));
               	pre[v] = u;
            }
        }
    }
}

int main(){
	
}