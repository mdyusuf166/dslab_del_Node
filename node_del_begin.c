#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode, *temp;
    int choice = 1;

    
    printf("Create the initial linked list:\n");
    while(choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if(newnode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("Enter value: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to insert another node? (1 = yes, 0 = no): ");
        scanf("%d", &choice);
    }

    
    if(head == NULL) {
        printf("\nList is already empty. Nothing to delete.\n");
    } else {
        temp = head;           // store old head
        head = head->next;     // move head to next node
        printf("\nDeleted node value: %d\n", temp->data);
        free(temp);            // free memory
    }

    
    printf("\nThe updated linked list is:\n");
    temp = head;
    if(temp == NULL) {
        printf("List is empty.\n");
    } else {
        while(temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}
