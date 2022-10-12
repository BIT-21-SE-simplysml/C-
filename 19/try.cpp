#include <stdio.h>
int timemorning,timeevening,distance;
int sum;
int carprice(int x, int y){
	int price;
    if(x <= 3)
    	price = 14;
    else if(y >= 23 || y < 5)
    	price = 14 + 2.76 * (x - 3);
        else
			price = 14 + 2.3 * (x - 3);
     return price;
    
}
int main(){
	timemorning = 9;
    timeevening = 18;
    distance = 12;
    sum = carprice(12, timemorning) + carprice(12, timeevening);
    printf("daily cost is %d", sum);
    return 0;
}
