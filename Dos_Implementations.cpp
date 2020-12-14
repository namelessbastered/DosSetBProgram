#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Dos_Header.h"
#include <string.h>


struct Node* newNode(char* data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy_s(node->data, data);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void print2DUtil(Node* root, int space)
{

    // Base case 
    if (root == NULL)
        return;

    // Increase distance between levels 
    space += COUNT;

    // Process right child first 
    print2DUtil(root->right, space);
    // Print current node after space 
    // count 
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf("  ");

    printf("%s<", root->data);

    // Process left child 
    print2DUtil(root->left, space);

}

void print2D(Node* root)
{
    // Pass initial space count as 0 
    print2DUtil(root, 0);
}

void printList(Node* root) {
}

Node* search(Node* root, char* data)
{

    if (root == NULL)
        return NULL;
    else if ((strcmp(root->data, data) == 0))
        return root;
    else {
        Node* left = search(root->left, data);
        return left ? left : search(root->right, data);
    }
}

void downline(Node* root, char* tmpUpID, char* tmpID) {

    int insDone = 0;

    Node* tmpHolder = search(root, tmpUpID);
    printf("\nNode found in: %p", tmpHolder);
    if (tmpHolder == NULL) {
        printf("\nERROR - UPLINE NOT FOUND!");
        insDone = 1;
    }
    if (insDone != 1 && tmpHolder->left == NULL) {
        tmpHolder->left = newNode(tmpID);
        insDone = 1;
    }
    if (insDone != 1 && tmpHolder->right == NULL) {
        tmpHolder->right = newNode(tmpID);
        insDone = 1;
    }

    insDone = 0;
}
