#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct StackNode
{
    int data;
    struct StackNode *next;
};

struct StackNode* newNode(int data)
{
    struct StackNode* stacknode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stacknode->data = data;
    stacknode->next = NULL;
    return stacknode;
}

int isEmpty(struct StackNode *root)
{
    return !root;
}

void push(struct StackNode** root, int data)
{
    struct StackNode* stacknode = newNode(data);
    stacknode->next = *root;
    *root = stacknode;
}

int pop(struct StackNode** root)
{
    if(isEmpty(*root))
    {
        return INT_MIN;
    }
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(struct StackNode* root)
{
    if(isEmpty(root))
        return INT_MIN;
    return root->data;
}


int main()
{
    struct StackNode* root = NULL;
    push(&root, 10);
    push(&root, 5);
    printf("%d",pop(&root));
    printf("%d",pop(&root));
    printf("%d",pop(&root));
    return 0;
}
