#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *curr1 = NULL, *curr2 = NULL;

void display(struct node *head){
	int data;
	while(head != NULL){
		printf("-->%d", head->data);
		head = head->next;
	}
	printf("\n");
}

struct node *new_Node(){
	int data;
	printf("enter data:\t");
	scanf("%d", &data);
	struct node *temp = NULL;
	temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void insert(struct node *head,struct node **curr){

	struct node *temp = new_Node();
	(*curr)->next = temp;
	*curr = temp;
}

int main(){
	int choice,intsert_option;
	while(1){
		printf("1. insert first list:\t 3. display:\t 4. exit:\t");
		scanf("%d", &choice);
		switch(choice){
			case 1: 
					printf("Enter list number which you want 1 or 2 \t");
					scanf("%d",&intsert_option);
					if( intsert_option == 1 ){
						if(head1 == NULL){
							head1 = new_Node();
							curr1 = head1;
						}else{
							//printf("%d \n",curr1->data);
							insert(head1,&curr1);
						}
					}else{
						if(head2 == NULL){
							head2 = new_Node();
							curr2 = head2;
						}else{
							insert(head2,&curr2);
						}
					}
					break;
			case 3: 
					printf("list one:\t");
					display(head1);
					printf("\n");
					printf("list two:\t");
					display(head2);
					printf("\n");
					break;
			case 4: exit(0);
					break;
		}
	}
}
