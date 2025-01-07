#include <stdio.h>
#include <string.h>

struct employee
{
  int id;
  char name[20];
  float sal;

} emp[3] =
  { {11, "Anuj", 45000.32}, {12, "Samad", 55500.12}, {13, "Abhishek",
						      6900.45} };

void
main ()
{

  struct employee *p = emp;
  int i;
  for (i = 0; i < 3; i++)
    {

      printf ("\nEmployee id is :%d\n", p->id);
      printf ("Employee name is :%s\n", p->name);
      printf ("Employee salary is :%.2f\n", p->sal);
      ++p;

    }


}
