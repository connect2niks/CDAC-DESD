#include <stdio.h>
int main() {
    char s1[10]="CDAC";
    char s2[10];
    int i;

    for (i = 0; s1[i] != '\0'; ++i) {
        s2[i] = s1[i];
    }

    s2[i] = '\0';
    printf("String s2: %s", s2);
    return 0;
}
