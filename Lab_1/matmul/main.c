#include "global.h"

int main()
{
    int num_row, num_col,i,j;
    int num_row_2, num_col_2;
    int k;
    FILE *fp= fopen("input.txt", "r");
    fscanf(fp, "%d %d", &num_row, &num_col);
    int mat1[num_row][num_col] ;

    for(i = 0 ; i < num_row; i++)
    {
        for(j = 0 ; j < num_col ; j++)
        {
           mat1[i][j] = rand();
        }
    }

    
    fscanf(fp, "%d %d", &num_row_2, &num_col_2);
    int mat2[num_row_2][num_col_2] ;
    
    for(i = 0 ; i < num_row_2; i++)
    {
        for(j = 0 ; j < num_col_2 ; j++)
        {
            mat2[i][j] = rand();
        }
    }
    
    if (num_col == num_row_2)
    {
        int mat[num_row][num_col_2] ;
        for(i = 0 ; i < num_row ; i++)
        {
            for(j = 0 ; j < num_col_2 ; j++)
            {
                int sum = 0 ;
                for( int k = 0 ; k < num_col ; k++)
                {
                    sum = sum + mat1[i][k]*mat2[k][j] ;
                    mat[i][j] = sum ;
                }
            } 
        }

        for( int i = 0 ; i < num_row ; i++)
        {
            for( int j = 0 ; j < num_col_2 ; j++ )
            {
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
