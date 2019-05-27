#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,n,s;
    s=0;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
       scanf("%d",&x);
       if(x<=0)
       {
           s++;
       }
    }
    printf("%d\n",s);
    return 0;
}
