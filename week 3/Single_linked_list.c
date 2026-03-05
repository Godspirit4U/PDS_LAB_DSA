#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
 
struct node* create() {
    struct node *head = NULL, *new_node = NULL , *temp = NULL;
    int choice = 1;
    while(choice == 1) {
        new_node = (struct node*) malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&new_node->data);
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            temp = head;
        }

        else {
            temp->next = new_node;
            temp = new_node;
        }
        printf("Press 1 to continue and 0 to stop.");
        scanf("%d",&choice);
    }
    return head;
}

void display(struct node* head) { 
    struct node *temp = head;

    while(temp != NULL) {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node* insert_at_last(struct node* head) {
    struct node *temp = head, *new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data of new node: ");
    scanf("%d",&new_node->data);
    new_node->next = NULL;

    if(head == NULL) {
        return new_node;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    return head;
}

struct node* insert_at_first(struct node* head) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data of new node: ");
    scanf("%d",&new_node->data);
    new_node->next = head;
    return new_node;
}

struct node* insert_at_any_position(struct node* head, int position) {
    if(position <= 0) {
        printf("Invalid position!\n");
        return head;
    }
    struct node *new_node = (struct node*)malloc(sizeof(struct node)), *temp = head;
    if(new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    printf("Enter the data of new node: ");
    scanf("%d",&new_node->data);
    new_node->next = NULL;

    if(head == NULL) {
        if(position == 1) {
            return new_node;
        }
        else {
            printf("Invalid position!\n");
            free(new_node);
            return head;
        }
    }
    
    if(position == 1) {
        new_node->next = head;
        return new_node;
    }

    for(int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(new_node);
        return head;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

struct node* delete_at_first(struct node *head) {
    struct node *temp = head;
    if(head==NULL)
    {
        printf("list is empty");
        return NULL;
    }
    head = head->next;
    free(temp);
    return head;
}

struct node* delete_at_last(struct node *head) {
    if(head == NULL) {
        printf("List is empty.");
        return NULL;
    }
    
    if(head->next == NULL) {
        free(head);
        return NULL;
    }
    
    struct node *temp = head, *prev = NULL;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    return head;

}


struct node* delete_at_any_position(struct node *head, int position) {
    struct node *temp = head, *prev = NULL;
    if(head == NULL) {
        printf("List is empty.");
        return NULL;
    }
    
    if(position == 1) {
        head = head->next;
        free(temp);
        return head;
    }
    
    for(int i = 1; i < position - 1; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

struct node* reverse_list(struct node *head) {
    struct node *p = NULL, *n = NULL, *c = head;
    while(c != NULL) {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    return p;
}

int main() {
    struct node *head = NULL;
    int choice, position;

    while(1) {
        printf("\n----- MENU -----\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete from Position\n");
        printf("9. Reverse List\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                head = create();
                break;

            case 2:
                display(head);
                break;

            case 3:
                head = insert_at_first(head);
                break;

            case 4:
                head = insert_at_last(head);
                break;

            case 5:
                printf("Enter position: ");
                scanf("%d", &position);
                head = insert_at_any_position(head, position);
                break;

            case 6:
                head = delete_at_first(head);
                break;

            case 7:
                head = delete_at_last(head);
                break;

            case 8:
                printf("Enter position: ");
                scanf("%d", &position);
                head = delete_at_any_position(head, position);
                break;

            case 9:
                head = reverse_list(head);
                break;

            case 10:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}