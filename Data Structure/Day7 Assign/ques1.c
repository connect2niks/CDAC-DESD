/*Implement Hash Table Data Structures with following three basic operations  using Open Addressing (Linear Probing). Implementations must resolve the expected collisions.

1. insert (i):  Insert ‘i’ in to the hash table
2. find(i): Find item with key ‘i’
3. remove(i): delete ‘i’ from the hash table

Write the Test  code to check the working of the program
*/

#include <stdio.h>
#define max 11

int a[max];
void create ();
int insert ();
void find ();
void display ();
void del ();
char ch[]="DELETED";
char *ptr_ch=ch;
void
main ()
{
  for (int i = 0; i < max; i++)
    a[i] = '\0';
  create ();
  display ();
  find ();
  insert ();
  display ();
  del();
  display();
  find();
  insert ();
  display();
}

void
create ()
{
  int l, n, k;
  printf ("Enter no. of Elements(1-10) you want to insert:");
  scanf ("%d", &n);
  for (int i = 1; i < n + 1; i++)
    {
      printf ("Enter key[%d]:", i);
      scanf ("%d", &k);
      l = k % max;
      while (a[l] != '\0')
	l = ++l % max;
      a[l] = k;
    }
}

int
insert ()
{
  int l, n, k;
  printf ("\nEnter key to insert:");
  scanf ("%d", &k);
  l = k % max;
  while (a[l] != '\0' && a[l]!='d')
  {
	  l = ++l % max;
 	 
  }
  a[l] = k;
}



void
display ()
{
  printf ("\n'0' indicates the location is empty\n");
  for (int i = 0; i < max; i++)
    {
	    if(a[i]=='d')
		    printf("DELETED ");
	    else
		    printf ("%d  ", a[i]);

    }
  printf ("\n");
}

void
find ()
{
  int l, k;
  printf ("\nEnter key value you want to search: ");
  scanf ("%d", &k);
  l = k % max;
  while (((a[l] != k) && (a[l] != '\0')) ||  (a[l]=='d'))
    l = ++l % max;
  if (a[l] != '\0')
    printf ("\nSearch successful at index- %d\n", l);
  else
    printf ("\nSearch unsuccessful\n");
}


void del()
{
int l,k;
printf("\nEnter element you want to delete: ");
scanf("%d",&k);
l=k%max;
while((a[l]!=k)&&(a[l]!='\0'))
        l=++l%max;
if(a[l]!='\0')
        a[l]='d';
else
        printf("\nValue not found\n");

}
