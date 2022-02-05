#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
void insert_beg(struct Node **,int);
void insert_end(struct Node **,int);
void insert_pos(struct Node **,int,int);
void delete_beg(struct Node **);
void delete_end(struct Node **);
void delete_pos(struct Node **,int);
void traversal(struct Node*);
struct Node* search(struct Node*,int);
int main(){
	int choice,want_continue,pos,data,key;
	printf("enter choice 1.insert_beg 2.insert_end 3.insert_pos 4.delete_beg 5.delete_end 6.delete_pos 7.traversal 8.search\n");
	struct Node *head = NULL,*r;
	do
	{
		printf("enter choice\n");
		scanf("%d",&choice);
		switch(choice){
		case 1:printf("enter the value at beg:");
			scanf("%d",&data);
			insert_beg(&head,data);
			break;
		case 2:printf("enter the value at end:");
		       scanf("%d",&data);
		       insert_end(&head,data);
		       break;	
		case 3:printf("enter the value and position");
			scanf("%d%d",&data,&pos);
			insert_pos(&head,data,pos);
			break;
		case 4:delete_beg(&head);
		       break;
		case 5:delete_end(&head);
		       break;
		case 6:printf("enter the position to delete:");
		       scanf("%d",&pos);
		       delete_pos(&head,pos);
		       break;              	
		case 7:traversal(head);
			break;
		case 8:printf("enter the key \n");
			scanf("%d",&key);
			r=search(head,key);
			if(r == NULL)
				printf("not found\n");
			else
				printf("SUccessfull\n");
			}
			printf("want to continue,enter 1 \n");
			scanf("%d",&want_continue);
			}
			while(want_continue == 1);
			return 0;
}
void insert_beg(struct Node **head,int data)
{	struct Node *p,*temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = data;
	p = *head;
	if(*head == NULL)
	{ 
	  temp -> next = temp;
	  *head = temp;
	}
	else
	{
	   while(p -> next != *head)
	   p = p -> next;
	
	temp -> next = *head;
	p -> next = temp;
	*head = temp;
	}
     }
   
   
void insert_end(struct Node **head,int data)
{
    struct Node *p, *temp, *q;     	
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    p = *head;
    if(*head == NULL)
    {
       temp -> next = temp;
       *head = temp;
    }
    else
    {
       while(p -> next != *head)
         p = p -> next;
         p -> next = temp;
         temp -> next = *head;   
    }
    }
    
void insert_pos(struct Node **head, int data,int pos) 
{ 
   struct Node *p,*temp,*q;
   int k = 1;
   temp = (struct Node *)malloc(sizeof(struct Node));
   temp -> data = data;
   p= *head;
   while(k < pos)
   { 
       q = p;
       p = p -> next;
       k++;
   }
   q -> next = temp;
   temp -> next = p;
   }
   
void delete_beg(struct Node **head)
{
   struct Node *p = *head, *q;
   
   if(*head == NULL)
   { 
      printf("empty cell\n");
      return;
   }
   if((*head) -> next == *head)
   { 
      *head = NULL;
      free(p);
   }
   else
   { q =p;
      while(p -> next != *head)
      {
         p = p -> next;
      }   
    *head = (*head) -> next;
    p -> next = *head;
    free(q);
    }
}
            
void delete_end(struct Node **head)
{
   struct Node *p = *head, *q;
   if(head == NULL)
   {
      printf("empty cell");
      return;
   }                         
   if((*head) -> next == *head)
   {
      *head = NULL;
      free(p);
   }   
   else
   {  
      while( p -> next != *head)
      {
         q = p;
         p = p -> next;
      }
      q -> next = *head;
      free(p);
    }
  }
  
void delete_pos(struct Node **head, int pos)
{
   struct Node *p, *q;
   int k=1;
   p = *head;
   while(k < pos)
   { 
      q = p;
      p = p -> next;
      k++;
   }
   q -> next = p -> next;
   free(p);
 }            	     

void traversal(struct Node *head)
{	struct Node *p;
	p = head;
	do
	{
          printf(“Linked List : \n”);
	   printf("%d\t",p -> data);
	   p = p -> next;
	}
	while(p != head);
}
struct Node* search(struct Node*head,int key)
{	struct Node*p;
	p = head;
	while(p != NULL)
	{	if(p -> data == key)
		{	return p;
		}
		p = p -> next;
		}
		return NULL;
}
