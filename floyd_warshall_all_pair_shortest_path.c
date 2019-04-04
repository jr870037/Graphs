#include <stdio.h>
#define INF 100
int min(int a, int b)
{
    return (a < b) ? a : b;
}
void main()
{
    int a[][4] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };
    int i, j, k, m = 4;
    for (k = 0; k < m; k++)
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < m; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}