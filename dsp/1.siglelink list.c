#include <stdio.h>
#include <stdlib.h>
struct Node{
     int data;
     struct Node *next;
 };
void insert(struct Node **,int,int);
void delete(struct Node **,int);
void traversal(struct Node *);
struct Node* search(struct Node *,int);
void midElement(struct Node *);
int main(){
    int choice,want_continue,pos,data,key;
    printf("Enter choice: 1.Insert, 2.Delete, 3.Traversal, 4.Search, 5.MiddleElement\n");
    struct Node *head = NULL,*r;
    do{
        printf("Enter choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the value and position:\n");
                   scanf("%d%d",&data,&pos);
                   insert(&head,data,pos); 
                   break;
            case 2:printf("enter the position to delete:\n");
                   scanf("%d",&pos);
                   delete(&head,pos);
                   break;
            case 3:traversal(head);
                   break;
            case 4:printf("enter the key:\n");
                   scanf("%d",&key);
                   r = search(head,key);
                   if(r == NULL){
                       printf("Not found\n");
                    }
                   else 
                       printf("successful\n");
                   break;
            case 5:midElement(head);
             }          
            printf("want to continue, enter 1\n");
            scanf("%d",&want_continue);
          }
          while(want_continue == 1);
            return 0;
        }    
void insert(struct Node **head,int data,int pos){
     struct Node *p,*q,*temp;
     int k=1;
     temp = (struct Node*)malloc(sizeof(struct Node));
     temp -> data = data;
     p = *head;
     if(pos == 1){
        temp -> next = *head;
        *head = temp;
       }
     else{
         while((p != NULL) && (k<pos))
         { 
            q = p;
            p = p -> next;
            k++;
          }
         q -> next = temp;
         temp -> next = p;
         } 
      }
void delete(struct Node **head,int pos){
     struct Node *p,*q;
     int k =1;
     p = *head;
     if(pos == 1){
        *head = (*head) -> next;
        free(p);
        }
     else{
         while((p != NULL) && (k<pos))
         {  
            q = p;
            p = p -> next;
            k++;
            }
     if(p == NULL)
     {
        printf("node does not exist");
      }
     else
     {
        q -> next = p -> next;
        free(p);
     }
   }
 }
void traversal(struct Node *head)
{
    struct Node *p;
    p = head;
    printf("Linked List:");
    while(p != NULL)	
    { 
         printf("%d\t",p -> data);
       p = p -> next;
     }
 }
struct Node* search(struct Node *head,int key){
     struct Node *p;
     p = head;
     while(p != NULL)
     {
        if(p -> data == key) 
        {  
           return p;
        }
        p = p -> next;
        }
     return NULL;
     }       
void midElement(struct Node *head)
{
     struct Node *p, *q;
     p = head;
     q = head;
     if(head != NULL)
     {
        while((p != NULL) && ((p -> next) != NULL))
        { 
           p = p -> next -> next;
           q = q -> next;
        }
         printf("Middle Element is ");
         printf("%d\n", q -> data);
      }     
 }      
 p = p -> next;
     }
 }


