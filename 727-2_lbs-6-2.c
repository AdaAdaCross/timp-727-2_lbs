#include <stdio.h>
#include <stdlib.h>
int	sorting_function(int	*arr,	int	arr_len)
{
    int i, j, k;
	int t;
	for(k = arr_len / 2; k > 0; k /= 2)
        for(i = k; i < arr_len; i++)
        {
            t = arr[i];
            for(j = i; j >= k; j -= k)
            {
                if(t < arr[j - k])
                    arr[j] = arr[j - k];
                else
                    break;
            }
            arr[j] = t;
        }
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

   sorting_function(arr,n);
   for (int i=0;i<n-1; i++)
 {
     printf("%d ", arr[i]);
 }
printf("%d\n", arr[n-1]);

    return 0;
}

