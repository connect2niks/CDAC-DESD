#include <stdio.h>

void change (char *s)
{
    for (int i = 0; s[i]; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
}

int main (void)
{
    char first[] = "HELLO WORLD";
    char *second = first;

    printf("%s\n", first);
    change(first);
    printf("%s\n", second);

    return 0;
}
