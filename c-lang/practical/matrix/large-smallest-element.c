
#include <stdio.h>

int main()
{
    int a[100][100], r, c;
    int i, j, max, min;

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

    max = a[0][0];
    min = a[0][0];

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(a[i][j] > max)
            {
                max = a[i][j];
            }

            if(a[i][j] < min)
            {
                min = a[i][j];
            }
        }
    }

    printf("Largest element = %d\n", max);
    printf("Smallest element = %d\n", min);

    return 0;
}
