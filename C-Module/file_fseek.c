/*Write a C program to demonstrate functionality of the fseek library function*/

#include<stdio.h>
int
main ()
{

  FILE *f;

  f = fopen ("file.txt", "w");	//open file in write mode

  fputs ("My name is Nikhil\t", f);	//print- My name is Nikhil

  fseek (f, 0, SEEK_END);	//use SEEK_END offset to 0 to append after first string

  fputs ("My name is Anchal", f);	//print- My name is Anchal

  fseek (f, 29, SEEK_SET);

  fputs ("Abhishek\n", f);	//overwrite anchal by setting cursor to 29th position of the string

  rewind (f);			//set cursor at the begining

  fseek (f, 11, SEEK_CUR);	//overwrite Nikhil 

  fputs ("Akhil.", f);


  fclose (f);
  return 0;

}
