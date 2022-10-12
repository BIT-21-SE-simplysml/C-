#include<stdio.h>
int main(){
    int n;
    while(scanf("%d", &n) == 1){
    	if(n <= 9 && n > 5){
    		printf("%d %d %d\n",2, 3, 6);
		}
		else printf("No solution\n");
	}
}