/*Take a numeric input in a List and show the list with every such input
When asked, print the list in reverse order*/

#include<stdio.h>
#include<stdlib.h>

void shove(int x);
void yield();
void insert(int x,int pos);
void printReverse();
struct Node* RevList();
struct Node{
	int data;
	struct Node* next;  
};

struct Node* Head = NULL;
struct Node* Previous = NULL;

void main(){
int num=0,position,prompt=0;
while (prompt!=4){
	printf("\n\nKey\tFunctions\n");
	printf("1\tPopulate\n");
	printf("2\tInsert in a specified location\n");
	printf("3\tPrint In Reverse Order\n");
	printf("4\tReverse the Linked List\n");
	printf("5\tExit\n\n");
	scanf("%d",&prompt);
	switch(prompt){
		case 1:{
			printf("Please enter a number: ");
			scanf("%d",&num);
			if (num== -1) break;
			else {
				shove(num);
				yield();
				}//case 1 else
			break;
			}//case 1
		case 2:{
			printf("Enter number and position separated by a space : ");
			scanf("%d%d",&num,&position);
			printf("\n");
			insert(num,position);
			yield();
			break;
			}//case 2
		case 3:{
			printReverse();
			break;
			}//case 3
		case 4:{
			RevList();
			yield();
			}//case 4
		case 5:
			break;
		default:{
			printf("Fuck You!!\n");
			break;
			}//deault case
		}//switch
	if (prompt==3) break;
}//mother while
}//main

void shove(int x){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	if (Head == NULL) {
		Head = temp;
	}//if
	else {
		Previous->next = temp;
		}//else
	Previous = temp;

}//shove

void yield(){
	struct Node*  i = Head;
	while (i!=NULL) {
		printf("%d ",(i->data));
		i = i->next;
	}//while
	printf("\n");
}//yield

void insert(int x,int pos){
	int _;
	struct Node* i=Head;
	for(_=1;_<pos-1;_++){
		i = i->next;
			}
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = i->next;
	i->next = temp;
}//insert

void printReverse(){
	struct Node* tail = NULL;
	struct Node* i = Head;
	printf("\n");
	while(tail!=Head){
		while(i->next!=tail){
			i = i->next;
				}//whileInner
		printf("%d ",i->data);
		tail = i;
		i = Head;
		}//whileOuter
	printf("\n");
}//printReverse

struct Node* RevList(){
    struct Node* tail = NULL;
    struct Node* i = Head;
    int temp;
    if (Head!=NULL){
    while (tail!=Head->next){
        while(i->next!=tail){
            temp = i->data;
            i->data = i->next->data;
            i->next->data = temp;
            i = i->next;
            }//inner while
        tail = i;
        i = Head;
    }//outer while
    }
}//RevList
