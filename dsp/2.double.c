#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node * next;
	struct Node * prev;
};
void insert(struct Node**,int,int);
void delete(struct Node**,int);
void traversal(struct Node*);
struct Node* search(struct Node*,int);
void middle(struct Node*);
int main(){
	int choice,want_continue,pos,data,key;
	printf("enter choice 1.insert 2.delete 3.traversal 4.search 5.Middle \n");
	struct Node *head = NULL,*r;
	do
	{
		printf("enter choice\n");
		scanf("%d",&choice);
		switch(choice){
		case 1:printf("enter the value and position\n");
			scanf("%d%d",&data,&pos);
			insert(&head,data,pos);
			break;
		case 2:printf("enter the position and delete\n");
			scanf("%d",&pos);
			delete(&head,pos);
			break;
		case 3:traversal(head);
			break;
		case 4:printf("enter the key \n");
			scanf("%d",&key);
			r=search(head,key);
			if(r == NULL)
				printf("not found\n");
			else
				printf("SUccessfull\n");
			break;
		case 5:middle(head);
			}
			printf("want to continue,enter 1 \n");
			scanf("%d",&want_continue);
			}
			while(want_continue == 1);
			return 0;
}
void insert(struct Node**head,int data,int pos)
{	struct Node *p,*temp;
	int k = 1;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = data;
	p = *head;
	if(pos == 1){
		temp -> next = *head;
		temp -> prev = NULL;
		if(*head){
			(*head) -> prev = temp;
		}
		*head = temp;
	}
	else{
		while((k<pos - 1) && (p -> next != NULL))
		{	p = p -> next;
			k++;
		}
		if(k != pos -1)
		{	printf("position does not exist\n");
			return ;
		}
		temp -> next = p -> next;
		temp -> prev = p;
		if(p -> next)
			p -> next -> prev = temp;
			p -> next = temp;
		}
}
void delete(struct Node**head ,int pos)
{	struct Node *p,*q;
	int k = 1;
	p = *head;
	if(pos == 1)
	{	*head = (*head) -> next;
		if(*head)
			(*head) -> prev = NULL;
		free(p);
	}
	else
	{	while((k < pos) && (p -> next != NULL))
		{	p = p-> next;
			k++;
		}
		if(k != pos)
		{	printf("position does not exist \n");
		return;
		}
		q = p -> prev;
		q -> next = p -> next;
		if(p -> next)
			p -> next -> prev = q;
		free(p);
		}
}
void traversal(struct Node*head)
{	struct Node*p;
	p = head;
	printf("Linked List:\n");
	while(p != NULL){
	printf("%d\n",p -> data);
	p = p -> next;
	}
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
void middle(struct Node*head)
{	struct Node *p,*q;
	p = head;
	q = head;
	if(head!=NULL){
		while((p!=NULL) && ((p -> next)!=NULL)){
		p = p -> next -> next;
		q = q -> next;
	}
	printf("Middle Element is ");
	printf("%d\n",q-> data);
	}
}	

