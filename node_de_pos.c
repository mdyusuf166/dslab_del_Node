#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode, *temp;
    int choice = 1, pos, i;

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

    
    printf("\nEnter the position to delete (starting from 1): ");
    scanf("%d", &pos);

    if(head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else if(pos == 1) {
        temp = head;
        head = head->next;
        printf("Deleted node value: %d\n", temp->data);
        free(temp);
    } else {
        struct node *prev = NULL;
        temp = head;
        i = 1;

        while(temp != NULL && i < pos) {
            prev = temp;
            temp = temp->next;
            i++;
        }

        if(temp == NULL) {
            printf("Invalid position! No node deleted.\n");
        } else {
            prev->next = temp->next;
            printf("Deleted node value: %d\n", temp->data);
            free(temp);
        }
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
