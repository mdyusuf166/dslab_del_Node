#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *prev;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode, *temp;
    int choice = 1;

    
    printf("Create the doubly linked list:\n");
    while(choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if(newnode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("Enter value: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        printf("Do you want to insert another node? (1 = yes, 0 = no): ");
        scanf("%d", &choice);
    }

    
    printf("\nDoubly linked list (forward):\n");
    temp = head;
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    
    printf("\nDoubly linked list (backward):\n");
    
    if(head != NULL) {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        while(temp != NULL) {
            printf("%d <-> ", temp->data);
            temp = temp->prev;
        }
        printf("NULL\n");
    }

    return 0;
}
