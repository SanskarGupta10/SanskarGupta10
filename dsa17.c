#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;

};

void linkedlistTraversal(struct node * a)
{
  while(a!=NULL)
  {
    printf("Element : %d\n",a->data);
    a=a->next;

  }

}
//insert the element in the linked list at end
struct node* insertATEnd(struct node* head,int data){
struct node *ptr=(struct node*)malloc(sizeof(struct node));
struct node *p=head;

while(p->next!=NULL)
{
    p = p->next;
    
}
ptr->data=data;
p->next=ptr;
ptr->next =NULL;
return ptr;

}


int main(){

struct node* head;  
struct node* second; 
struct node* third;   

//Allocate memnory for nodes in the linked list in heap
head=(struct node*)malloc(sizeof(struct node));
second=(struct node*)malloc(sizeof(struct node));
third=(struct node*)malloc(sizeof(struct node));

//link first and second node
head->data=7;
head->next = second;
//link second and third node
second->data =11;
second->next=third;

//terminate the list at third node
third->data=66;
third->next = NULL;

 linkedlistTraversal(head);
 head =insertATEnd(head,45);
 linkedlistTraversal(head);

return 0;
}