#include<stdio.h>
int main()
{
    int i;
    int m=20, n=49;

    for(i=m; i<=n;i++){
        if(i%2==0)
        {
            printf("%d is even\n", i);
        }
    }
     for(i=m; i<=n;i++){
        if(i%2!=0)
        {
            printf("%d is odd\n", i);
        }
    }

    return 0;
}