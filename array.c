#include<stdio.h>
#include<stdlib.h>

int main()
{
    int (*arr1)[4] = (int(*)[]) malloc((4)*sizeof(int)) ;
    int (*arr2)[4] = (int(*)[]) malloc((4)*sizeof(int)) ;
    int arr3[2][2] ;
    int sum =0;
    printf("Enter 1 matrix ");
    for(int i=0 ; i<2 ; i++)
    {
        for(int j=0; j<2; j++)
        {
            scanf("%d", *(arr1+i)+j) ;
        }
    }
    printf("Enter 1 matrix ");
    for(int i=0 ; i<2 ; i++)
    {
        for(int j=0; j<2; j++)
        {
            scanf("%d", *(arr2+i)+j) ;
        }
    }
    for(int i=0 ; i<2 ; i++)
    {
        for(int j=0; j<2; j++)
        {
            arr3[i][j] = **(arr1+i)+j +**(arr2+i)+j;
        }
    }
    printf("Addition of matrix is \n ");
    for(int i=0 ; i<2 ; i++)
    {
        for(int j=0 ; j<2 ; j++)
        {
            printf("%d",arr3[i][j]) ;
            printf("\t") ;
            
        }
        printf("\n") ;
    }
    for(int i=0 ; i<2 ; i++)
    {
        for(int j=0; j<2; j++)
        {
            arr3[i][j] = 0;
            for(int k=0; k<2; k++)
            {
                arr3[i][j] =arr3[i][j]+*(*(arr1+i)+k)* (*(*arr2+k)+j);
            }
            printf("%d", arr3[i][j]) ;
                
        }
    }
    /*printf("Mutiplication of matrix is \n ");
    for(int i=0 ; i<2 ; i++)
    {
        for(int j=0 ; j<2 ; j++)
        {
            printf("%d",arr3[i][j]) ;
            printf("\t") ;
            
        }
        printf("\n") ;
    }*/

    return(0) ;
}