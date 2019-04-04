#include<stdio.h>
#define MAXNODES 5 //enter the number of nodes in the graph
void main()
{
    int i,j,k;
    int adj[MAXNODES][MAXNODES],path[MAXNODES][MAXNODES];
    printf("\nEnter the values:\n");
    for(i=0;i<MAXNODES;i++)
    {
        printf("\nThis is the %d row:\n",i);
        for(int j=0;j<MAXNODES;j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    //copying the adj matrix in the path matrix
    for (i = 0; i < MAXNODES; i++)
    {
        for (j = 0; j < MAXNODES; j++)
        {
            path[i][j]=adj[i][j];
        }
    }

    //deploying the warshall algorithm.

    for(k=0;k<MAXNODES;k++)
    {
        for(i=0;i<MAXNODES;i++)
        {
            if(path[i][k]==1)
            for(j=0;j<MAXNODES;j++)
            {
                path[i][j]=path[i][j]||path[k][j];
            }
        }
    }

    //printing the path matrix 

    printf("\nPrinting the transitive closure matrix:\n");
    for(i=0;i<MAXNODES;i++)
    {
        for(j=0;j<MAXNODES;j++)
        {
            printf("%d\t",path[i][j]);
        }
        printf("\n");
    }

}