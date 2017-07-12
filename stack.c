#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void push(int a);
int pop(void);
void show(void);

struct Node{
	int data;
	struct Node* prev;
};

struct Node* Tail = NULL;

void main(){
	int prompt;
	int dat;
	while (prompt!=3){
		printf("\n\tKeys\tFunctions\n");
		printf("\t1\tPush\n");
		printf("\t2\tPop\n");
		printf("\t3\tExit\n\n");
		printf("Enter response: ");
		scanf("%d",&prompt);
		switch(prompt){
			case 1:{
				printf("\nEnter the number: ");
				scanf("%d",&dat);
				push(dat);
				show();
				break;
				}//case 1
			case 2:{
				printf("\nThe popped element is: %d\n ",pop());
				printf("The entire array is:\n");
				show();
				break;
				}//case 2
			case 3:{
				break;
				}//case 3
			default:{
				printf("\nInvalid Input.\n");
				break;
				}//default
			}//switch
		}//mother while
}//main loop

void push(int a){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = a;
	temp->prev = Tail;
	Tail = temp;
}//push

int pop(void){
	int tempDat = Tail->data;
	struct Node* temp = Tail->prev;
	free(Tail);
	Tail = temp;
	return(tempDat);
}//pop

void show(void){
	struct Node* i = Tail;
	while (i!=NULL){
		printf(" ||%d|| ",i->data);
		i = i->prev;
		}//while
	printf("\n");
}//show
