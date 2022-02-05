#include <stdio.h>

void insertionsort(int a[], int n);
int main()
{
int i,a[20],n;
    printf("enter the size of an array:");
    scanf("%d",&n);
    printf("enter the elements in array:");
    for(i=0;i<n;i++)
{
        scanf("%d",&a[i]);
}
    insertionsort(a,n);
    printf("Elements after sorting:\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
    }
    
void insertionsort(int a[],int n)
{
   int i,j,index;
   for(i=0;i<n;i++)
   {
      index = a[i];
      j = i;
      while((j>0) && (a[j-1] > index))
      {
            a[j] = a[j-1];
            j = j-1;
            }
            a[j] = index;
            }
 }           
       

