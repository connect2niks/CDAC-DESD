#include <stdio.h>
#include <string.h>

#define MAX 1024  // supports very large numbers

int main() {
    char a[MAX], b[MAX], result[MAX + 1];

    printf("Enter two numbers: ");
    scanf("%1023s %1023s", a, b);

    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int k = 0, carry = 0;

    // add from right to left
    while (i >= 0 || j >= 0 || carry) {
        int digit_a = (i >= 0) ? a[i--] - '0' : 0;
        int digit_b = (j >= 0) ? b[j--] - '0' : 0;

        int sum = digit_a + digit_b + carry;
        result[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    result[k] = '\0';

    // reverse result
    for (int l = 0; l < k / 2; l++) {
        char temp = result[l];
        result[l] = result[k - l - 1];
        result[k - l - 1] = temp;
    }

    printf("Sum: %s\n", result);
    return 0;
}
