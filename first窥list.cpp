//created by __simplysml__ 2022/2/26
//#include <stdio.h> 
//#include <stdlib.h>
//#include<math.h> 
//#include<string.h>
#define ll long long 
#include<bits/stdc++.h>
using namespace std;
const ll md = 1e9 + 7;
list<int> l;
void tries(int n, int st){
	list<int>::iterator p1;
	if(n == 1){
		for(p1 = l.begin(); p1 != l.end(); p1++){
			printf("%d ", *p1);
		}
		printf("%d\n", n);
		return;
	}
	for(int i = st; i <= n / 2; i++){
		l.push_back(i);
		tries(n - i, i);
		l.pop_back();
	}
	for(p1 = l.begin(); p1!=l.end(); p1++){
		printf("%d ", *p1);
	}
	printf("%d\n", n);
	return;
}

int main(){ 
	int n;
	scanf("%d", &n);
	tries(n, 1);
}