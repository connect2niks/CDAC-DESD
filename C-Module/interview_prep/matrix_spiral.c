#include <stdio.h>

#define N 4

int main() {
    int mat[N][N] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };

    int top = 0, bottom = N - 1;
    int left = 0, right = N - 1;

    while (top <= bottom && left <= right) {
        // Print top row (left → right)
        for (int i = left; i <= right; i++)
            printf("%d ", mat[top][i]);
        top++;

        // Print right column (top → bottom)
        for (int i = top; i <= bottom; i++)
            printf("%d ", mat[i][right]);
        right--;

        // Print bottom row (right → left)
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", mat[bottom][i]);
            bottom--;
        }

        // Print left column (bottom → top)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", mat[i][left]);
            left++;
        }
    }

    printf("\n");
    return 0;
}

