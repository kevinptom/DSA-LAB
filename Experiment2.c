// Sparse matrix addition and Compact matrix of the Transpose Matrix
#include <stdio.h>

int main() {
    int row1,col1,row2,col2;
    
    printf("Enter the number of rows and columns of the matrix1:");
    scanf("%d%d",&row1,&col1);
    
    printf("Enter the number of rows and columns of the matrix2:");
    scanf("%d%d",&row2,&col2);
    
    if (row1 != row2 && col1 != col2){
        printf("The matrix dimensions are not same\n");
        printf("=============Thank You!============");
        return 0;
    }
    
    int Matrix1[row1][col1];
    printf("Enter the elements of Matrix1:");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            scanf("%d",&Matrix1[i][j]);
        }
    }
    
    int Matrix2[row2][col2];
    printf("Enter the elements of Matrix2:");
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            scanf("%d",&Matrix2[i][j]);
        }
    }
    
    int Matrix3[row1][col2];
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            Matrix3[i][j] = Matrix1[i][j] + Matrix2[i][j];
        }
    }
    
    printf("The first sparse matrix\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            printf("%d  ",Matrix1[i][j]);
        }
        printf("\n");
    }
    
    printf("The second sparse matrix\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            printf("%d  ",Matrix2[i][j]);
        }
        printf("\n");
    }
    
    printf("The resultant sparse matrix\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            printf("%d  ",Matrix3[i][j]);
        }
        printf("\n");
    }
    
    int Transpose[col1][row1];
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            Transpose[j][i] = Matrix3[i][j];
        }
    }
    
    printf("The Transpose of the resultant sparse matrix:\n");
    for(int i=0;i<col1;i++){
        for(int j=0;j<row1;j++){
            printf("%d  ",Transpose[i][j]);
        }
        printf("\n");
    }
    
    int count = 0;
    for(int i=0;i<col1;i++){
        for(int j=0;j<row1;j++){
            if(Transpose[i][j] != 0){
                count++;
            }
        }
    }
    
    printf("The compact matrix of the resultant transpose matrix is (row column value):\n");
    
    printf("%d  %d  %d\n",col1,row1,count);
    for(int i=0;i<col1;i++){
        for(int j=0;j<row1;j++){
            if(Transpose[i][j] != 0){
                printf("%d  %d  %d\n",i,j,Transpose[i][j]);
            }
        }
        
    }
    
    
    return 0;
}
