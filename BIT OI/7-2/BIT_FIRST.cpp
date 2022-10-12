#include<bits/stdc++.h> 
using namespace std;
int a[3];
int main(){
    int n,k;
    while(scanf("%d %d", &k, &n) == 2){
        for(int i = 0; i < 3; i++){
            a[i] = -1;
        }
        for(int i = 0; i < k; i++){
            int temp;
            cin >> temp;
            a[temp % 3] = max(a[temp % 3], temp);
        }
        string s = "";
        int mx = max(a[0],max(a[1], a[2]));
        if(mx % 3 == 0){
            if(mx == 0 && n != 1){
				cout << -1 << endl;
				continue;
            }
			for(int i = 0; i < n; i++){
                s += char(mx + '0');
            }
            cout << s << endl;
        }
        if(mx % 3 == 1){
            if(n % 3 == 0){
                for(int i = 0; i < n; i++){
                    s += char(a[1] + '0');
                }
                cout << s << endl;
            }
            if(n % 3 == 1){
                if((a[0] == -1 && a[2] == -1) || (n == 1 && a[0] == -1)){
                    s = "-1"; 
					cout << s << endl;
                    continue;
                }
                if(n == 1){
					cout << a[0] << endl;
					continue;
                }
                if(a[0] == -1){
                    for(int i = 0; i < n - 2; i++){
                        s += char(a[1] + '0');
                    }
                    s += char(a[2] + '0');
                    s += char(a[2] + '0');
                    cout << s << endl;
                    continue;
                }
                for(int i = 0; i < n - 1; i++){
                    s += char(a[1] + '0');
                }
                s += char(a[0] + '0');
                cout << s << endl;
            }
            if(n % 3 == 2){
                if((a[0] == -1 && a[2] == -1) || (a[0] == 0 && n == 2 && a[2] == -1)){
                    s = "-1";
					cout << s << endl;
                    continue;
                }
                if(n == 2 && a[2] == -1){
					s += char(a[0] + '0');
					s += char(a[0] + '0');
					cout << s << endl;
                	continue;
				}
                if(n == 2){
                    s += char(mx + '0');
					s += char(a[2] + '0');
                    cout << s << endl;
                    continue;
                }
                if(a[2] == -1){
                    for(int i = 0; i < n - 2; i++){
                        s += char(a[1] + '0');
                    }
                    s += char(a[0] + '0');
                    s += char(a[0] + '0');
                    cout << s << endl;
                    continue;
                }
                for(int i = 0; i < n - 1; i++){
                    s += char(a[1] + '0');
                }
                s += char(a[2] + '0');
                cout << s << endl;
            }
        }
        if(mx % 3 == 2){
           if(n % 3 == 0){
                for(int i = 0; i < n; i++){
                    s += char(mx + '0');
                }
                cout << s << endl;
            }
            if(n % 3 == 1){
                if((a[0] == -1 && a[1] == -1) || (n == 1 && a[0] == -1)){
                    s = "-1";
					cout << s << endl;
                    continue;
                }
                if(n == 1){
					cout << a[0] << endl;
					continue;
                }
                if(a[0] == -1){
                    for(int i = 0; i < n - 2; i++){
                        s += char(mx + '0');
                    }
                    s += char(a[1] + '0');
                    s += char(a[1] + '0');
                    cout << s << endl;
                    continue;
                }
                for(int i = 0; i < n - 1; i++){
                    s += char(mx + '0');
                }
                s += char(a[0] + '0');
                cout << s << endl;           
            }
            if(n % 3 == 2){
                if((a[0] == -1 && a[1] == -1)||(a[0] == 0 && n == 2 && a[1] == -1)){
                    s = "-1";
					cout << s << endl;
                    continue;
                }
                if(n == 2 && a[1] == -1){
					s += char(a[0] + '0');
					s += char(a[0] + '0');
					cout << s << endl;
					continue;
                }
                if(n == 2){
                    s += char(mx + '0');
					s += char(a[1] + '0');
                    cout << s << endl;
                    continue;
                }
                if(a[1] == -1){
                    for(int i = 0; i < n - 2; i++){
                        s += char(mx + '0');
                    }
                    s += char(a[0] + '0');
                    s += char(a[0] + '0');
                    cout << s << endl;
                    continue;
                }
                for(int i = 0; i < n - 1; i++){
                    s += char(mx + '0');
                }
                s += char(a[1] + '0');
                cout << s << endl;
            }            
        }
    }
    return 0;
}
