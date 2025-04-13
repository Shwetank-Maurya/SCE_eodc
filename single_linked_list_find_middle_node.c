#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
void*data;
struct Node*next;
}Node;
Node*createNode(void*data){
Node*newNode=(Node*)malloc(sizeof(Node));
if(!newNode){
printf("Memory Allocation failed");
exit(1);
}
newNode->data=data;
newNode->next=NULL;
return newNode;
}
Node*findMiddle(Node*head){
if(head==NULL){
return NULL;
}
Node*slow=head;
Node*fast=head;
while(fast!=NULL&&fast->next!=NULL){
slow=slow->next;
fast=fast->next->next;
}
return slow;
}
void printlist(Node*head,void(*printData)(void*)){
Node*temp=head;
while(temp!=NULL){
printData(temp->data);
temp=temp->next;
printf("     ");
}
printf("\n");
}
void printInt(void*data){
printf("%d",*(int*)data);
}
void freelist(Node*head){
Node*temp;
while(head!=NULL){
temp=head;
head=head->next;
free(temp);
}
}
int main(){
Node*head=createNode((void*)&(int){1});
head->next=createNode((void*)&(int){2});
head->next->next=createNode((void*)&(int){3});
head->next->next->next=createNode((void*)&(int){4});
head->next->next->next->next=createNode((void*)&(int){5});
printf("List:");
printlist(head,printInt);
Node*middle=findMiddle(head);
printf("Middle Node:");
printInt(middle->data);
printf("\n");
freelist(head);
return 0;
}
