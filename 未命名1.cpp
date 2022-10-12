#include<bits/stdc++.h>
using namespace std;

int main()
{
 srand(time(0));
 cout << 1 << endl;
 int n = rand() % 10001;
//int n = 1;
  for (int i = 0; i < n; i++)  cout << char(rand() % 2 + '0');
 cout << '\n';     
// n = rand() % 10001; 
  for (int i = 0; i < n; i++)  cout << char(rand() % 2 + '0');
 cout << '\n'; 
}