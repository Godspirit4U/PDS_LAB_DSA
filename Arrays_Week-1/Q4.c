#include <stdio.h>

int delete_beginning(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

int delete_end(int arr[], int size) {
    return size - 1;
}

int delete_position(int arr[], int size, int pos) {
    if(pos < 1 || pos > size) {
        printf("Invalid position\n");
        return size;
    }
    for(int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

int main() {

    int size;
    scanf("%d",&size);
    int arr[size + 10];

    for(int i = 0; i < size; i++) scanf("%d",&arr[i]);

    int opt;
    scanf("%d",&opt);

    if(opt == 1) size = delete_beginning(arr, size);
    else if(opt == 2) size = delete_end(arr, size);
    else if(opt == 3) {
        int pos;
        scanf("%d",&pos);
        size = delete_position(arr, size, pos);
    }

    for(int i = 0; i < size; i++) printf("%d ",arr[i]);

    return 0;
}