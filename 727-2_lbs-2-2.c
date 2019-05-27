#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,n,s;
    s=0;
    scanf("%d",&n);
    int i;
    for(i=1;i<n+1;i++)
    {
       scanf("%d",&x);
       if(i%2==1)
       {
           s+=x*x;
       }
    }
    printf("%d\n",s);
    return 0;
}
