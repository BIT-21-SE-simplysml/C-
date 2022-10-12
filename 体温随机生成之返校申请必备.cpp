#include<bits/stdc++.h>
#include<time.h>
#include<cstdlib>
#include<sstream>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define SZ(x) ((int)(x).size())
#define fastin ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
stringstream s;
typedef long long ll;
ll mknum(int wei){
	ll now=0;
	for(int i=1;i<=wei;i++){
		now=10ll*now+rand()%10;
	}
	return now;
}
void str(int len){
	for(int i=1;i<=len;i++){
		putchar('a'+rand()%3);
	}putchar('\n');
}
mt19937 rd(time(0));
int main(int argc,char *argv[]){
	int random;
	if(argc>1){
		s.clear();
		s<<argv[1];
		s>>random;
	}
	srand(random);
	std::mt19937 rd(random);
	int T=1;
	//cout<<T<<endl;
	int num = 2;
	int day = 17;
	while(T--){
//		int x=rd() % (3600 * 24) + 8;
	//	int y = rd() % 2 + 2;
//		printf("孙哥今天的npy见面数:%d\n", x);
	//	printf("%d %d\n",x,y);
		for(int i = 0; i < 14; i++){
			printf("%d.%d %.1f℃\n", num, day, rd() % 10 * 1.0 / 10 + 36);
			day++;
			if(day > 28){
				day = 1;
				num = 3;
			}
	//		printf("%d ",rd() % 1000 + 1);
//			int y = rd() % 2 + 2;
			
		}
		printf("\n");
	}
	return 0;
}
