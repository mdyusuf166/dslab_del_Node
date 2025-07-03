#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode, *temp;
    int choice = 1;

    
    printf("Create the circular linked list:\n");
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
            newnode->next = head;  // Point to itself
        } else {
            temp->next = newnode;
            newnode->next = head;
            temp = newnode;
        }

        printf("Do you want to insert another node? (1 = yes, 0 = no): ");
        scanf("%d", &choice);
    }

    
    printf("\nThe circular linked list is:\n");
    if(head == NULL) {
        printf("List is empty.\n");
    } else {
        temp = head;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while(temp != head);
        printf("(back to head)\n");
    }

    return 0;
}
