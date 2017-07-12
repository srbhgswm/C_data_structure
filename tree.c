/*Store data in tree form with the scheme of greater in right and smaller in left*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root = NULL;

void treeIns(struct Node** rootPtr, int x);
void treeTraversal(struct Node** rootPtr);

void main(){
	int num,prompt=0;
	while(prompt!=2){
		printf("\n1\tPopulate\n");
		printf("2\tExit\n");
		printf("\nEnter Your Choice: ");
		scanf("%d",&prompt);
		switch(prompt){
			case 1:
				printf("\nEnter a number: ");
				scanf("%d",&num);
				treeIns(&root,num);
				printf("\n");
				treeTraversal(&root);
				break;
			case 2:
				break;
			default:
				printf("\nFuck Off!!\n");
				break;
				}//switch
		}//while
}//main

void treeIns(struct Node** rootPtr, int x){
	if ((*rootPtr) == NULL){
		*rootPtr = (struct Node*)malloc(sizeof(struct Node));
		(*rootPtr)->data = x;
		(*rootPtr)->left = NULL;
		(*rootPtr)->right = NULL;
		return;
			}//if
	if (x<=root->data){
		 treeIns(&((*rootPtr)->left),x);
			}//if smaller
	else if (x>root->data){
		treeIns(&((*rootPtr)->right),x);
				}//else if greater
}//treeIns

void treeTraversal(struct Node** rootPtr){
	if ((*rootPtr)==NULL) return;
	printf("%d ",(*rootPtr)->data);
	treeTraversal(&((*rootPtr)->left));
	treeTraversal(&((*rootPtr)->right));
}//treeTraversal
