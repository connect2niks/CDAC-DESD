#include <stdio.h>
#include <string.h>

void reverse(char *str, int start, int end)
{
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    char str[] = "my name is nikhil";
    int start = 0;
    int len = strlen(str);

    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            reverse(str, start, i - 1);
            start = i + 1;
        }
    }

    printf("%s\n", str);
    return 0;
}
