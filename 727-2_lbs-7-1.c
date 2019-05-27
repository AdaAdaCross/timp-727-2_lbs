#include <stdio.h>
#include <stdlib.h>

int	sorting_function_1(int	*arr,	int	arr_left, int arr_right)
{
    int l=arr_left, r=arr_right, temp;
    int piv = arr[(l+r)/2];
    while(l<=r)
    {
        while(arr[l]<piv) l++;
        while(arr[r]>piv) r--;
        if(l<=r)
        {
            temp=arr[l];
            arr[l]=arr[r];
            arr[r]=temp;
            l++;
            r--;
        }
    }
    if (arr_left<r)sorting_function_1(arr,arr_left,r);
    if (arr_right>l)sorting_function_1(arr,l,arr_right);
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr;

    arr = (int*)malloc(sizeof(int)*n);
 for (int i=0;i<n; i++)
 {
     scanf("%d", &arr[i]);
    }

   sorting_function_1(arr,0,n-1);
   for (int i=0;i<n-1; i++)
 {
     printf("%d ", arr[i]);
 }
printf("%d\n", arr[n-1]);

    return 0;
}
