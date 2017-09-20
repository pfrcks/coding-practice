#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* nd = (struct node*)malloc(sizeof(struct node));
    nd->data = data;
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

void printInorder(struct node* tree)
{
    if(tree == NULL)
        return;
    printInorder(tree->left);
    printf("%d ", tree->data);
    printInorder(tree->right);
}

struct node* bstSearch(struct node* tree, int data)
{
    if(tree == NULL)
        return NULL;
    if(tree->data == data)
        return tree;
    if(tree->data < data)
        return bstSearch(tree->right, data);
    else
        return bstSearch(tree->left, data);
}

int isBST(struct node* tree, int min, int max)
{
    if(tree==NULL)
        return 1;
    if(tree->data < min || tree->data > max)
        return 0;
    return isBST(tree->left, min, tree->data -1) &&
        isBST(tree->right, tree->data+1, max);
}

int checkBST(struct node* tree)
{
    return isBST(tree, INT_MIN, INT_MAX);
}

struct node* insertBST(struct node* tree, int data)
{
    if(tree==NULL)
        return newNode(data);
    if(tree->data > data)
        tree->left = insertBST(tree->left, data);
    else if(tree->data < data)
        tree->right = insertBST(tree->right, data);

    return tree;
}

int main()
{
    struct node* root = newNode(5);
    root->right = newNode(3);
    root->left = newNode(2);
    root->left->right = newNode(3);
    printf("%d ",checkBST(root));
    return 0;
}
