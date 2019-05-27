#include <stdio.h>
#include <stdlib.h>

int	sorting_function_1(int	*arr,	int	arr_len)
{
    int n = 0;
    double fakt = 1.2473309;
    double step = arr_len - 1;
    int temp;
    int istep;
    while (step >= 1)
    {
        istep=(int)(step+0.5);
        for (int i = 0; i + istep <arr_len; ++i)
			{
			    n++;
				if (arr[i] > arr[i + istep])
				{
				    temp = arr[i + istep];
				    arr[i + istep]=arr[i];
				    arr[i] = temp;
					n++;
				}

			}
			step /= fakt;
		}
		return n;
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

   sorting_function_1(arr,n);
   for (int i=0;i<n-1; i++)
 {
     printf("%d ", arr[i]);
 }
printf("%d\n", arr[n-1]);

    return 0;
}

