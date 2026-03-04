#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node* create() {
    struct node *head = NULL, *temp = NULL, *new_node = NULL;
    int choice = 1;

    while(choice == 1) {
        new_node = (struct node*) malloc(sizeof(struct node));

        printf("Enter the data: ");
        scanf("%d",&new_node->data);

        new_node->prev = NULL;
        new_node->next = NULL;

        if(head == NULL) {
            head = new_node;
            temp = head;
        }
        else {
            temp->next = new_node;
            new_node->prev = temp;
            temp = new_node;
        }

        printf("Press 1 to continue and 0 to stop: ");
        scanf("%d",&choice);
    }

    return head;
}

void display_forward(struct node *head) {
    struct node *temp = head;

    while(temp != NULL) {
        printf("%d<->",temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void display_backward(struct node *head) {
    struct node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }

    while(temp != NULL) {
        printf("%d<->",temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

struct node* insert_at_first(struct node *head) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data of new node: ");
    scanf("%d",&new_node->data);

    new_node->prev = NULL;
    new_node->next = head;

    if(head != NULL)
        head->prev = new_node;

    return new_node;
}

struct node* insert_at_last(struct node *head) {
    struct node *temp = head;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data of new node: ");
    scanf("%d",&new_node->data);

    new_node->next = NULL;

    if(head == NULL) {
        new_node->prev = NULL;
        return new_node;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;

    return head;
}

struct node* insert_at_any_position(struct node *head, int position) {
    struct node *temp = head;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data of new node: ");
    scanf("%d",&new_node->data);

    if(position == 1) {
        new_node->prev = NULL;
        new_node->next = head;

        if(head != NULL)
            head->prev = new_node;

        return new_node;
    }

    for(int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Invalid position\n");
        free(new_node);
        return head;
    }

    new_node->next = temp->next;
    new_node->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = new_node;

    temp->next = new_node;

    return head;
}

struct node* delete_at_first(struct node *head) {
    if(head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct node *temp = head;

    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(temp);

    return head;
}

struct node* delete_at_last(struct node *head) {
    struct node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }

    if(temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);

    return head;
}

struct node* delete_at_any_position(struct node *head, int position) {
    struct node *temp = head;

    if(position == 1) {
        return delete_at_first(head);
    }

    for(int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Invalid position\n");
        return head;
    }

    temp->prev->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    return head;
}

struct node* reverse_list(struct node *head) {
    struct node *current = head;
    struct node *temp = NULL;

    while(current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if(temp != NULL)
        head = temp->prev;

    return head;
}

int main() {

    struct node *head = NULL;
    int choice, position;

    while(1) {

        printf("\n----- MENU -----\n");
        printf("1. Create List\n");
        printf("2. Display Forward\n");
        printf("3. Display Backward\n");
        printf("4. Insert at Beginning\n");
        printf("5. Insert at End\n");
        printf("6. Insert at Position\n");
        printf("7. Delete from Beginning\n");
        printf("8. Delete from End\n");
        printf("9. Delete from Position\n");
        printf("10. Reverse List\n");
        printf("11. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) {

            case 1:
                head = create();
                break;

            case 2:
                display_forward(head);
                break;

            case 3:
                display_backward(head);
                break;

            case 4:
                head = insert_at_first(head);
                break;

            case 5:
                head = insert_at_last(head);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d",&position);
                head = insert_at_any_position(head, position);
                break;

            case 7:
                head = delete_at_first(head);
                break;

            case 8:
                head = delete_at_last(head);
                break;

            case 9:
                printf("Enter position: ");
                scanf("%d",&position);
                head = delete_at_any_position(head, position);
                break;

            case 10:
                head = reverse_list(head);
                break;

            case 11:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}