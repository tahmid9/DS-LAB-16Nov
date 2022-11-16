
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
    if (node){
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);}


}

void printPreorder(struct node* node)
{
    if (node)
        {
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
        }
}

void printPostorder(struct node* node)
{
    if (node)
        {
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
        }
}


int main()
{
    struct node* root = newNode(6);
    root->left = newNode(5);
    root->right = newNode(8);
    root->left->left = newNode(3);
    root->left->right = newNode(4);


      printf("Inorder traversal of binary tree is \n");
    printInorder(root);

    printf("\nPreorder traversal of binary tree is \n");
    printPreorder(root);

    printf("\nPostorder traversal of binary tree is \n");
    printPostorder(root);


    return 0;
}
