#include<stdio.h>
#include<stdlib.h>
float add(float a,float b);
float subtract(float a,float b);
float multiply(float a,float b);
float divide(float a,float b);
int main(){
float(*operation)(float,float);
float num1,num2;
int choice;
printf("\nSimple Calculator\n");
printf("Select an Operation\n");
printf("1.Addition\n");
printf("2.Subtraction\n");
printf("3.Multiplication\n");
printf("4.Division\n");
scanf("%d",&choice);
printf("Enter both numbers:");
scanf("%f%f",&num1,&num2);
switch(choice){
case 1:
operation=add;
break;
case 2:
operation=subtract;
break;
case 3:
operation=multiply;
break;
case 4:
if(num2==0){
printf("Error:Division by zero is not allowed.\n");
return -1;
}
operation=divide;
break;
default:
printf("Enter a valid choice\n");
return -1;
}
float result=operation(num1,num2);
printf("Result:%.2f\n",result);
return 0;
}
float add(float a,float b){
return a+b;
}
float subtract(float a,float b){
return a-b;
}
float multiply(float a,float b){
return a*b;
}
float divide(float a,float b){
return a/b;
}
