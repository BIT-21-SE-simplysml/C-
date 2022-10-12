#include<bits/stdc++.h>
using namespace std;

bool check(int mid){
	// if wants to go left
	return true;
	// else 
	return false; 
}

void binary__search(int l, int r){
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid))r = mid - 1;
		else l = mid + 1;//r is the first false,l is the first true;
	} 
	//real number; l,r is real too.
	for(int i = 0; i < 100; i++){
		for(int i = 0; i < n; i++){
			double mid = (l + r) / 2;
			if(check (mid)) r = mid;
			else l = mid; 
		}
	}
}

