#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    (*head) = newNode;
}

void insertAfter(struct Node* prev, int data)
{
    if (prev == NULL)
    {
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prev->next;
    prev->next = newNode;
}

void appendAfter(struct Node** head, int data)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
    struct Node* last = (*head);
    while(last->next !=NULL)
        last = last->next;
    last->next = newnode;
    return;
}

void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}

void deleteFirstOccurence(struct Node** head, int data)
{
	if(*head == NULL)
		return;
    struct Node* temp = *head, *prev;
    if((*head)->data == data)
    {
        (*head) = (*head)->next;
        free(temp);
        return;
    }
    while(temp->data != data && temp!=NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

int main()
{
	struct Node* head = NULL;
	appendAfter(&head, 10);
	push(&head, 7);
	appendAfter(&head, 5);
	insertAfter(head->next, 8);
    printList(head);
    deleteFirstOccurence(&head, 7);
    deleteFirstOccurence(&head, 5);
	printList(head);
	return 0;
}
