#include<bits/stdc++.h>
using namespace std;
struct i{
	int num,ans;
}; 
bool cmp1(i x, i y){
	return x.ans < y.ans;
}
bool cmp2(i x, i y){
	return x.num < y.num;
}
int a[200001];
i l[200001];
i dl[200001];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		string s;
		cin >> s;
		int likes = 0; int dislikes = 0; 
		for(int i = 0; i < n; i++){
			if(s[i] == '0'){
				dl[dislikes].ans = a[i];
				dl[dislikes].num = dislikes;
				dislikes ++;
			}
			else {
				l[likes].ans = a[i];
				l[likes].num = likes;
				likes ++;
			}
		}
		sort(l, l + likes, cmp1);
		sort(dl, dl + dislikes, cmp1);
		for(int i = 0; i < likes; i++){
			l[i]. ans = dislikes + i + 1;
//			cout << l[i].ans;
		}
		for(int i = 0; i < dislikes; i++)
			dl[i]. ans = i + 1;
		sort(l, l + likes, cmp2);
		sort(dl, dl + dislikes, cmp2);
		likes = 0; dislikes = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '0'){
				cout << dl[dislikes].ans << ' ' ;
				dislikes++;
			}
			else{
				cout << l[likes].ans << ' ';
				likes ++;
			}
		}
		cout << endl;
	}
	return 0;
} 
