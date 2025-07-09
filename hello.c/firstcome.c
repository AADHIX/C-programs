#include <stdio.h>
int main()

{


    int n,i;

    // process call

    printf("Enter the number of procsses");
    scanf("%d", &n);

    // arrays to store processes 

    int pid[n];
    int at[n];
    int bt[n];
    int ct[n];
    int tat[n];
    int wt[n];

        // Input the process details

        for( i = 0;i < n;i++)
        {
                printf("The processes is %d",i + 1);
                pid[i] = i + 1; 


                printf("Arrival time : ");
                scanf("%d" , &at[i]);

                printf("Burst time : ");
                scanf("%d", &bt[i]);

                printf("\n");


        }


    










    return 0;
}