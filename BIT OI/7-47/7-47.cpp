#include<bits/stdc++.h> 
using namespace std;
int main(){
    int t;
    cin >> t; 
    while(t--){
        int a,w,h;
        cin >> a >> h >> w;
        h -= a;
        w += 2 * a;
        if(h > 129)
            cout << "ni li hai! ";
        if(h == 129){
            cout << "wan mei! ";
        }
        if(h < 129){
            cout << "duo chi yu! ";
        }
        if(w > 25)
            cout << "shao chi rou!" << endl;
        if(w == 25){
            cout << "wan mei!" << endl;
        }
        if(w < 25){
            cout << "duo chi rou!" << endl;
        }
    }
    return 0;
}
