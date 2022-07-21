#include<stdio.h>

void main()
{
        int A[20], N, temp, i, j;

        printf("\n ENTER THE NUMBER OF TERMS: ");
        scanf("%d", &N);
        printf("\n ENTER THE ELEMENTS OF THE ARRAY:");
        for(i=0; i<N; i++)
        {
         scanf("\n%d", &A[i]);
        }

	for(i=1; i<N; i++)
        {
                temp = A[i];
                j = i-1;
                while(temp < A[j] && j>=0)
                {
                   A[j+1] = A[j];
                   j = j-1;
                }
                A[j+1] = temp;
        }

        printf("\nTHE ASCENDING ORDER LIST IS...:\n");
        for(i=0; i<N; i++)
        printf("\n %d", A[i]);
}

