#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the number of element of array:");
    scanf("%d",&n);
    int*arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL){
        printf("Memory Allocation Failed \n");
        return 1;
    }
    printf("Enter %d elements :\n",n);
    for(int i=0;i<n;i++){
        printf("Enter the %d element:",i+1);
        scanf("%d",arr+i);
    }
    printf("\n Array elements in reverse order:\n");
    for(int i=n-1;i>=0;i--){
        printf("%d",*(arr+i));
        printf("     ");

    }
    free(arr);
    return 0;
}