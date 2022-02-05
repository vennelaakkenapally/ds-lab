#include <stdio.h>

void bubblesort(int a[], int n);
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
    bubblesort(a,n);
    printf(“Elements after sorting:\t”);
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
    }
    
void bubblesort(int a[],int n)
{
int i,j,t;
    for(i=0;i<n-1;i++)
{
        for(j=0;j<n-1-i;j++)
{
            if(a[j] > a[j+1])
{
              t = a[j];
              a[j] = a[j+1];
              a[j+1] = t;
             }
         }
     }

