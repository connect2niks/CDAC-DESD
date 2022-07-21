#include<stdio.h>

int main()
{
      int a[20],n,elem,flag=0,pos,i;

      printf("ENTER THE ARRAY SIZE\t");
      scanf("%d",&n);
      printf("ENTER THE ARRAY\t");
      for(i=0;i<n;i++)
      scanf("%d",&a[i]);
      printf("ENTER THE ELEMENT TO BE SEARCHED\t");
      scanf("%d",&elem);
      for(i=0;i<n;i++)
      {
            if(elem==a[i])
            {
                 flag=1;
                 pos=i;
                 break;
            }
      }
      if(flag==1)
         printf("THE ELEMENT %d IS AT %d POSITION",elem,i+1);
         else
         printf("ELEMENT NOT FOUND");
}

