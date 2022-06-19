//student record management system

#include <stdio.h>
struct srms
{
  int r;
  char n[20];
  char s[2];
  float e;
} stud[5];

int
main ()
{
  int i, c, j;
  for (i = 1; i < 6; i++)
    {

      printf ("Enter rollno. :");
      scanf ("%d", &stud[i].r);

      printf ("Enter name of student :");
      scanf ("%s", &stud[i].n);

      printf ("Enter exam score :");
      scanf ("%f", &stud[i].e);

      printf ("Enter sex :");
      scanf ("%s", &stud[i].s);

    }
  printf ("\n\n*******Student Record*******\n\n");
  for (i = 1; i < 6; i++)
    {

      printf ("(%d)-Roll no. :%d, Name :%s, Sex :%s, Exam score :%.2f\n\n ",
	      i, stud[i].r, stud[i].n, stud[i].s, stud[i].e);

    }

 // for student who gets maximum marks
  c = stud[1].e;
  for (i = 2; i < 6; i++)
    {
      if (c < stud[i].e)
	{

	  c = stud[i].e;
	}

    }

  for (i = 1; i < 6; i++)
    {
      if (c == stud[i].e)
	{
	  printf ("Student who gets the minimum score :%s\n", stud[i].n);
	}
    }

//for student who gets minimum marks

  c = stud[1].e;
  for (i = 2; i < 6; i++)
    {
      if (c > stud[i].e)
	{

	  c = stud[i].e;
	}

    }

  for (i = 1; i < 6; i++)
    {
      if (c == stud[i].e)
	{
	  printf ("Student who gets the minimum score :%s\n", stud[i].n);
	}
    }

  return 0;
}
