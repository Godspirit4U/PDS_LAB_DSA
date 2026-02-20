// Insert an element at:
// 1. Beginning
// 2. End
// 3. Specific position

#include <stdio.h>

int insert_at_first(int arr[], int size, int num) {
    for(int i = size; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = num;
    return size + 1;
}

int insert_at_pos(int arr[], int size, int num, int pos) {
    for(int i = size; i >= pos; i--) {
        if(pos < 1 || pos > size + 1) {
        printf("Invalid position!\n");
    return size;
}
        arr[i] = arr[i-1];
    }
    arr[pos - 1] = num;
    return size + 1;
}

int insert_at_last(int arr[], int size, int num) {
    arr[size] = num;
    return size + 1;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size + 20];

    for(int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("The array is :-\n");
    for(int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }
    int opt;
    printf("\nInsert element at:-\n\t1) Beginning\n\t2) Specific position\n\t3) End\n");
    printf(" Choose the option: ");
    scanf("%d", &opt);
    switch(opt) {
        case 1:
            {int num;
            printf("Enter value to insert at beginning: ");
            scanf("%d", &num);
            size = insert_at_first(arr, size, num);
            break;}
        case 2:
           { int num, pos;
            printf("Enter value to insert at specific position: ");
            scanf("%d", &num);
            printf("Enter the position to insert: ");
            scanf("%d", &pos);
            size = insert_at_pos(arr, size, num, pos);
            break;}
        case 3:
            {int num;
            printf("Enter value to insert at end: ");
            scanf("%d", &num);
            size = insert_at_last(arr, size, num);
            break;}
        default:
                printf("Invalid! position\n");
                break;
    }
    printf("The updated array is :-\n");
    for(int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }
    return 0;
}