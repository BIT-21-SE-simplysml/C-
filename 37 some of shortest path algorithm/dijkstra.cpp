#include<bits/stdc++.h>
using namespace std; 
struct edge{
    int d,p;
};
struct dis_pri{
    int dis;
    int pri;
};
bool visited[1002];
edge e[1002][1002];
dis_pri dispri[1002];
int main(){
    int m,n;
    while(scanf("%d %d", &n, &m) == 2){
        if(n == 0 && m == 0)
            return 0;
        for(int i = 0; i < 1002; i++){
            for(int j = 0; j < 1002; j++){
                e[i][j].d = 0x3f3f3f3f;
                e[i][j].p = 0x3f3f3f3f;
                visited[i] = false;
            }
        }
        for(int i = 1; i <= m; i++){
            int a1,b1,d1,p1;
            scanf("%d %d %d %d", &a1, &b1, &d1, &p1);
            e[a1][b1].d = d1;
            e[b1][a1].d = d1;
            e[a1][b1].p = p1;
            e[b1][a1].p = p1;
        }
        int target,start;
        scanf("%d %d", &start, &target);
        for(int i = 1; i <= n; i++){
            dispri[i].dis = 0x3f3f3f3f;
            dispri[i].pri = 0x3f3f3f3f;
        }
        dispri[start].dis = 0;
        dispri[start].pri = 0;
        visited[start] = false;
        for(int i = 1; i <= n; i++){
            int md,mp,x;
            mp = 0x3f3f3f3f;
            md = 0x3f3f3f3f;
            x = 0;
            for(int j = 1; j <= n; j++){
 //               cout << visited[j] << endl;
                if(visited[j] == false && ((dispri[j].dis < md)||(dispri[j].dis == md && dispri[j].pri < mp))){
                    md = dispri[j].dis;
                    mp = dispri[j].pri;
                    x = j;
 //                   cout << "yes";
                }
            }
            visited[x] = true;
 //           cout << x << endl;
            if(x == target){
                cout << md << ' ' << mp << endl;
                break;
            }
            for(int j = 1; j <= n; j++){
                    if(e[x][j].d + md < dispri[j].dis){
                        dispri[j].dis = e[x][j].d + md;
                        dispri[j].pri = e[x][j].p + mp;
                    }
                    if(e[x][j].d + md == dispri[j].dis){
                        dispri[j].pri = min(e[x][j].p + mp,dispri[j].pri);
                    }
                }
           }
    }
    return 0;
}
