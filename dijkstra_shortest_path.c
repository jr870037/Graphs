#include<stdio.h>
#include<time.h>
#define INFI 20
#define V 5
#define MEMBER 1
#define NONMEMBER 0
void main()
{
    int weight[V][V]={
        {0,6,20,1,20},
        {6,0,5,2,2},
        {20,5,0,20,5},
        {1,2,20,0,1},
        {20,2,5,1,0}
    };
    //                 //   0  1  2  3  4  5  6  7  8
    // int weight[V][V] = {{0, 4,20,20,20,20,20, 8,20},
    //                     {4, 0, 8,20,20,20,20,11,20},
    //                     {20,8, 0, 7,20, 4,20,20, 2},
    //                     {20,20,7, 0, 9,14,20,20,20},
    //                     {20,20,20,9, 0,10,20,20,20},
    //                     {20,20,4,14,10, 0, 2,20,20},
    //                     {0, 20,20,20,20,2, 0, 1, 6},
    //                     {8, 11,20,20,20,20,1, 0, 7},
    //                     {20,20, 2,20,20,20,6, 7, 0}};
    int s=0,t=3,pd,precede[V],perm[V],current,i,k,dc,smalldist,newdist,distance[V];
		clock_t ti;
		ti=clock();
    for(i=0;i<V;i++)
    {
        perm[i]=NONMEMBER;
        distance[i]=INFI;
        precede[i]=-1;
    }
    perm[s]=MEMBER;
    distance[s]=0;
    current=s;
    while(current!=t)
    {
        smalldist=INFI;
        dc=distance[current];
        for(i=0;i<V;i++)
        {
            if(perm[i]==NONMEMBER)
            {
                newdist=dc+weight[current][i];
                if(newdist<distance[i])
                {
                    distance[i]=newdist;
                    precede[i]=current;
                }//end if;
                if(distance[i]<smalldist)
                {
                    smalldist=distance[i];
                    k=i;
                }
            }
        }
        current=k;
        perm[current]=MEMBER;
    }
    pd=distance[t];
    ti=clock();
    printf("Printing pd: %d\n",pd);
    // printf("Time taken to find the shortest path: %f",(double)ti/CLOCKS_PER_SEC);
    printf("\nPrinting the precede array:\n ");
    for(i=0;i<V;i++)
    printf("%d\t",precede[i]);

}
