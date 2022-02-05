#include <stdio.h>

int linear_search(int[],int,int);
 
int main()
{
    int i, a[20],key, n, p;
      printf("enter the size of an array:");
      scanf("%d",&n);
    printf("enter the elements in an array:");
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    printf("element to be searched:");
    scanf("%d",&key);
  p = linear_search(a,n,key);
    if(p>=0)
    {
       printf("element found at %d",p);
    }
    else
    {
       printf("element not found");
    }
return 0;
}

int linear_search(int a[20],int n,int key)
{
    int i;
       for(i=0;i<n;i++)
       {
           if(key == a[i])
           {
                return i;
           } 
}
                return -1;
}
