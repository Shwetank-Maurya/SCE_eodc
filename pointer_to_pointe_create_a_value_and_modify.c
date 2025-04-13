#include<stdio.h>
int main()
{
    int num=10;
    int*ptr=&num;
    int **ptr2=&ptr;
    printf("Direct access to num:%d\n",num);
    printf(" Access through pointer ptr:%d\n",*ptr);
    printf(" Access through pointer to pointer:%d\n",**ptr2);
    **ptr2=25;
    printf("\n After modifying using Pointer to Pointer :\n");
    printf("\nDirect access to num:%d\n",num);
    printf("Access through pointer ptr:%d \n ",*ptr);
    printf("Access through pointer to pointer ptr2 :%d \n ",**ptr2);
    return 0;
}