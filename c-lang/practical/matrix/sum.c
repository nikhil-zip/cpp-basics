
#include <stdio.h>

int main()
{
    int a[100][100], r, c;
    int i, j, rowSum, colSum;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 0; i < r; i++)
    {
        rowSum = 0;

        for(j = 0; j < c; j++)
        {
            rowSum = rowSum + a[i][j];
        }

        printf("Row %d sum = %d\n", i + 1, rowSum);
    }
    for(j = 0; j < c; j++)
    {
        colSum = 0;

        for(i = 0; i < r; i++)
        {
            colSum = colSum + a[i][j];
        }

        printf("Column %d sum = %d\n", j + 1, colSum);
    }

    return 0;
}
