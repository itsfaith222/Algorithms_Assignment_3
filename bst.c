/************************************************************************************* 
* This program implements a binary search tree
* 
*
* Modified by:
* Date:
*************************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

//BSTREE defines a type which is a pointer to a node
typedef struct node *BSTREE;

//node contains data, pointer to left and right child
struct node
{
	int data;
	BSTREE left;
	BSTREE right;
};



//The following are functions that you will need to define below (after the main function)
//in order to complete #1 of the Assignment
BSTREE insert(BSTREE root, int number);
BSTREE find(BSTREE root, int number);
void inOrderTraversal(BSTREE subtree, FILE *fp);



int main()
{
	//Create a pointer call root, which points to the root of the tree;
	//Initially, root points to NULL
	BSTREE root = NULL;

	//ADD YOUR CODE HERE for #2 and #3: automate as much as possible (e.g. don't hard-code n)
	

}

//This function creates a new node whose "data" is number and adds this
//node to the binary search tree rooted at "root"; it returns the root of the tree.
//DO NOT ADD DUPLICATES!
BSTREE insert(BSTREE root, int number)
{
	//HINT: If root points to NULL, you will need to allocate memory space for the node: 
	if (!root) {
		root = (BSTREE)malloc(sizeof(struct node));
		root->left = NULL;
		root->right = NULL;
		root->data = number;
		return root;
	}
	//ADD YOUR CODE HERE FOR THE REST OF THIS FUNCTION. DON'T FORGET TO RETURN SOMETHING

}


//This function returns a pointer to the node in the tree rooted at "root"
//containing "number" or NULL if "number" is not found
BSTREE find(BSTREE root, int number)
{
    //ADD YOUR CODE HERE. DON'T FORGET TO RETURN SOMETHING
	BSTREE current = root;

	while(current != NULL){
		if (current->data != number){
			if (current->data > number){
				current = current->left;
			}
			else{
				current = current->right;
			}
		}
		else{
			return current;
		}
	}
	return NULL;
}


//This function performs an inorder traversal of the binary
//search tree rooted at "root", by printing to a designated output file the
//values of the nodes as they are visited.
void inOrderTraversal(BSTREE root, FILE *fp)
{
	//ADD YOUR CODE HERE

}


