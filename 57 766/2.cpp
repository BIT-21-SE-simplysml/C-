#include<stdio.h>

int Function(int n)
{
    for (int i=2; i< sqrt(n); i++)
    {
        if ( n%i == 0 )
            return 0;
    }
    return 1;
}

int main(void)
{
    int N;
    int count=0;
    scanf("%d",&N);
    for(int i=2; i<=N; i++)
    {
        if(Function(i)==1 && Function(i+2)==1)
        {
            printf("%5d �� %5d ����������\n",i,i+2);
            count++;//����+1
        }
    }
    return 0;
}


