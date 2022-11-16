
#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* left;
    struct node* right;
};


struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}


void printInorder(struct node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    printf("%d ", node->data);

    /* now recur on right child */
    printInorder(node->right);
}

void printPreorder(struct node* node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    printf("%d ", node->data);

    /* then recur on left subtree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}

void printPostorder(struct node* node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    printf("%d ", node->data);
}

/* Driver code*/
int main()
{
    struct node* root = newNode(6);
    root->left = newNode(5);
    root->right = newNode(8);
    root->left->left = newNode(3);
    root->left->right = newNode(4);

      // calling function
      printf("\nInorder traversal of binary tree is \n");
    printInorder(root);

    printf("\nPreorder traversal of binary tree is \n");
    printPreorder(root);

    printf("\nPostorder traversal of binary tree is \n");
    printPostorder(root);


    return 0;
}