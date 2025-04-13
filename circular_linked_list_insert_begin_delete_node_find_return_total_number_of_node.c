#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
int data;
struct Node*next;
}Node;
void insertatBeginning(Node**head,int data){
Node*newNode=(Node*)malloc(sizeof(Node));
newNode->data=data;
if(*head==NULL){
newNode->next=newNode;
*head=newNode;
return;
}
Node*temp=*head;
while(temp->next!=*head){
temp=temp->next;
}
temp->next=newNode;
newNode->next=*head;
*head=newNode;
}
void deleteNode(Node**head){
if(*head==NULL){
printf("List is empty,Nothing to delete here\n");
return;
}
Node*temp=*head;
if(temp->next==*head){
free(temp);
*head=NULL;
return;
}
while(temp->next->next!=*head){
temp=temp->next;
}
Node*toDelete=temp->next;
temp->next=*head;
free(toDelete);
}
int Finding_Node(Node**head,int value){
Node*temp=*head;
int position=0;
if(*head==NULL){
printf("Nothing to find\n");
return -1;
}
do{
if(temp->data==value){
return position;
}
temp=temp->next;
position++;
}while(temp!=*head);
return -1;
}
int Total_Node(Node**head){
Node*temp=*head;
int count=0;
if(*head==NULL){
return count;
}
do{
count++;
temp=temp->next;
}while(temp!=*head);
return count;
}
void display(Node**head){
if(*head==NULL){
printf("No elements in the Linked List\n");
return;
}
Node*temp=*head;
do{
printf("%d ",temp->data);
temp=temp->next;
}while(temp!=*head);
printf("\n");
}
int main(){
Node*head=NULL;
insertatBeginning(&head,10);
insertatBeginning(&head,40);
insertatBeginning(&head,100);
display(&head);
printf("Total nodes:%d\n",Total_Node(&head));
printf("Position of 100:%d\n",Finding_Node(&head,100));
deleteNode(&head);
display(&head);
return 0;
}
