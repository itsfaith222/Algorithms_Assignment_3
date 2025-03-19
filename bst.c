/************************************************************************************* 
* This program implements a binary search tree
* 
*
* Modified by: Mahimaa Vardini BR, Faith Aikhionbare, Samarpita Sharma 
* Date: Thursday, March 20th, 2025
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
	
	int choice, num;
	int count = 0;
	clock_t start;
    double executionTime;
    FILE *fp;

	//for each choice make a loop that iterates between these numbers for n
	int inputs[] = {2, 4, 6, 8, 10};

	//ADD YOUR CODE HERE for #2 and #3: automate as much as possible (e.g. don't hard-code n)
	printf("1. Insert number 1 to n. \n");
	printf("2. Insert first n number found in dataToBuildTree.txt file. \n");
	printf("Choose an option: ");
	scanf("%d", &choice);

	if(choice == 1){ //insert to tree 1 to n
		for(int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++){
			for(int k = 0; k < 5; k++){
				start = clock(); // start the timer

				//each run rest BST root to be empty 
				root = NULL;

				//insert rest of option one code here
				for(int num = 1; num <= inputs[i]; num++){
					root = insert(root, num);
				}
		
				//calculate and display execution time
				executionTime = (double)(clock() - start) / CLOCKS_PER_SEC * 1000;
				printf("Run %d \n", k+1);
				printf("Time taken to insert %d numbers: %.4f seconds\n", inputs[i], executionTime);
			}
			printf("\n"); // empty line to separate each input being ran
		}

	}else if(choice == 2){ //insert first n from file

		//insert rest of choice 2 code here - iterate through n then make inner loop 5 
		for(int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++){
			
			for(int j = 0; j < 5; j ++){
				start = clock(); // start timer
				fp = fopen("dataToBuildTree.txt", "r"); // open file 

				// for each run the tree needs to be empyt so this resets the tree to empty
				root = NULL;
				
				//make sure file is not empyt 
				if(fp == NULL){
					printf("Error opening file\n");
					exit(1);
				}

				// reset count to keep tract of the numbers being inserted from file
				count = 0;

				//insert each number into binary search tree
				while(count < inputs[i] && fscanf(fp, "%d", &num) == 1){
					root = insert(root, num);
					count ++;
				}
				
				//calculate and display execution time
				executionTime = (double)(clock() - start) / CLOCKS_PER_SEC * 1000;
				printf("Run #%d: \n", j+1);
				printf("Time taken to insert %d numbers: %.4f seconds\n", inputs[i], executionTime);
				fclose(fp);
			}
			printf("\n"); // empty line to separate each input being ran
		}

	}else{
		//neither choice 
		printf("Invalid choice!");
		return 1;
	}
	return 0;

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
	
	BSTREE current = root; //to keep track of which node we are currently at 
	BSTREE parent = NULL; // to keep track of the previos node for when we find an empty child

	//while loop 
	while(current != NULL){
		parent = current; // sets th parent pointer to current
		if (current->data > number){  // check if number is smaller than current node
			//move to the left child 
			current = current->left;
		}else if (current->data < number){ // check if number is bigger than current node
			//move to the right child
			current = current->right;
		}else if (current->data == number){ // check is number is the same as the current node
			return root; // if same return root so we done insert duplicates. 
		}
	}

	//after we find an null child insert number to parent left or right child
	// first we have to create the node for the new number 
	BSTREE newNode = (BSTREE)malloc(sizeof(struct node));
	newNode->data = number;
	newNode->left = NULL;
	newNode->right = NULL;

	if (parent->data > number){
		parent->left = newNode; // insert new node as left child of parent if number is smaller
	}else {
		parent->right = newNode; // insert new node as right child of parent if number is bigger
	}
	return root;
}


//This function returns a pointer to the node in the tree rooted at "root"
//containing "number" or NULL if "number" is not found
BSTREE find(BSTREE root, int number)
{
	BSTREE current = root; // pointer to keep track of the current node

	while(current != NULL){ // make sure the current node is not null
		if (current->data != number){ //if current node = number it returns current node
			if (current->data > number){ // if not then check if number is bigger or smaller to move to next node
				current = current->left; // moves to left node
			}
			else{
				current = current->right; // moves to right node
			}
		}
		else{
			return current; 
		}
	}
	return NULL; // if current node is null weather that is the root or a null child we return null 
}


//This function performs an inorder traversal of the binary
//search tree rooted at "root", by printing to a designated output file the
//values of the nodes as they are visited.
void inOrderTraversal(BSTREE root, FILE *fp)
{
	//if root is null return to pevious call else continue
	if(root == NULL){
		return;
	}

	BSTREE current = root; // the parent node is current

	//find smalles number/most left node using recursion
	inOrderTraversal(current->left, fp);
	//prints data of parent node when execution returns to the recusive function. 
	fprintf(fp, "%d ", current->data);
	//now go through the right side of the parent node repeating this function finding the most left node
	inOrderTraversal(current->right, fp); 
	 
}




