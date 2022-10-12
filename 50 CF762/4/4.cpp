#include<bits/stdc++.h>
using namespace std;

long long a[200001];
long long num[200001];
long long s[200001];
long long s2[200001];

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			num[a[i]]++;
		}
		s[0] = num[0];
		for(int i = 1; i <= n; i++){
			s[i] = s[i - 1] + num[i]; 
	//		cout << s[i] << ' ';
		}
	//	cout << endl;
		sort(a, a + n);
		s2[0] = a[0];
		for(int i = 1; i <= n; i++){
			s2[i] = s2[i - 1] + a[i];
		}
		long long sum = 0;
		bool p = false;
		stack<int> st; 
		for(int i = 0; i < n; i++){
			if(i != 0)
				if(p || s[i - 1] <= i - 1){
					p = true;
					cout << -1 << ' ';
					continue;
				}
			if(num[i] > 1){
				for(int j = num[i]; j > 1; j--)
					st.push(i);
			}
			cout << sum + num[i] << ' ';
			if(num[i] == 0 && i != 0){
				if(st.empty()){
					p = true;
					continue;
				}
				int temp = st.top();
				st.pop();
				sum += i - temp;
			}
		}
		if(p || s[n - 1] <= n - 1)
			cout << -1 << endl;
		else {
			long long ans = (1ll * n * (n - 1) / 2 - s2[n - 1]);
			cout << ans << endl;
		}
		cout << endl;
		for(int i = 0; i <= n; i++){
			a[i] = 0;
			num[i] = 0;
			s[i] = 0;
			s2[i] = 0;
		} 
	}
	return 0;
}
