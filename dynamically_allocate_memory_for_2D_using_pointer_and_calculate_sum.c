#include<stdio.h>
#include<stdlib.h>
int main(){
    int row,cols;
    int sum=0;
    printf("enter the number of rows:");
    scanf("%d",&row);
    printf("enter the number of columns:");
    scanf("%d",&cols);
    int*matrix=(int*)malloc(row*cols*sizeof(int));
    if(matrix==NULL){
        printf("Memory alloaction Failed");
        return -1;
    }
    printf("enter the matrix element\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<cols;j++){
            printf("element [%d][%d]:",i+1,j+1);
            *(matrix+i* cols+j)=0;
            scanf("%d",(matrix+i * cols+j));

        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<cols;j++){
            sum+=*(matrix+i *cols+j);

        }
    }
    printf("\n The Matrix is:\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<cols;j++){
            printf("%d       ",*(matrix+i * cols+j));
        }
        printf("\n");
    }
    printf("\n The sum of all the elements in the matrix is:%d \n",sum);
    free(matrix);
    return 0;

}