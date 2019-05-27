#include <stdio.h>
#include <stdlib.h>

void siftDown(int *numbers, int root, int bottom)
{
    int maxChild;
    int done = 0;
    while((root*2<=bottom) && (done!=1))
    {
        if(root*2==bottom) maxChild=bottom;
        else
        {
          if(numbers[root*2]<numbers[root*2+1])  maxChild = root*2+1;
          else maxChild = root*2;
        }
        if(numbers[root]<numbers[maxChild])
        {
            int temp;
            temp = numbers[root];
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else done=1;
    }
}

int sorting_function(int *arr, int arr_len)
{
    double tmp;
    tmp=(arr_len/2.0 + 0.5) - 1;

  for (int i = (int)tmp; i >= 0; i--)
    siftDown(arr, i, arr_len - 1);
  for (int i = arr_len - 1; i >= 1; i--)
  {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    siftDown(arr, 0, i - 1);
  }
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

   sorting_function(arr,n);
   for (int i=0;i<n-1; i++)
 {
     printf("%d ", arr[i]);
 }
printf("%d\n", arr[n-1]);

    return 0;
}

