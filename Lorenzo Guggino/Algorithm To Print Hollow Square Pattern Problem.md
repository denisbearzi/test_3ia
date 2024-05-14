#include <stdio.h>

int main()
{
    int i, j, N;

    /* Code Block To Get The Input From The User */
    printf("Enter number of rows To Print Hollow Square : ");
    scanf("%d", &N);

   
    for(i=1; i<=N; i++)
    {
       
        for(j=1; j<=N; j++)
        {
            if(i==1 || i==N || j==1 || j==N)
            {
                /* Code Bloack To Print The First & Last Column */
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        
        printf("\n");
    }

    return 0;
}

