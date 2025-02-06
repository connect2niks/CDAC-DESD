#include <stdio.h>
#include <string.h>
#pragma pack(1)
struct sandbox
{
	char name[20];
	int *pid;
	char domain[20];

};

void display(struct sandbox);
void display1(struct sandbox *);
struct sandbox change(struct sandbox);
struct sandbox *func(struct sandbox *);
int main()
{
	int x = 1234;
	struct sandbox sb = {"Niks",&x,"EOS"};
	struct sandbox *sbptr;
	display(sb);
	display1(&sb);
	sb = change(sb);
	display(sb);
	sbptr = func(&sb);
	display1(sbptr);	
	return 0;
}

void display(struct sandbox snd)
{
	printf("%s",snd.name);
	printf("%d",*(snd.pid));
	printf("%s\n",snd.domain);
}

void display1(struct sandbox *snd)
{
        printf("%s",snd->name);
        printf("%d",*(snd->pid));
        printf("%s\n",snd->domain);

}

struct sandbox change(struct sandbox snd)
{
	*(snd.pid) = 4321;
	return snd;
}

struct sandbox *func(struct sandbox *snd)
{
	strncpy(snd->name,"Nikhil",sizeof("Nikhil"));
	return snd;
}


