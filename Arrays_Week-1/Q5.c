#include <stdio.h>

int delete_value(int arr[], int size, int value) {

    int index = -1;

    for(int i = 0; i < size; i++) {
        if(arr[i] == value) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Value not found\n");
        return size;
    }

    for(int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

int main() {

    int size;
    scanf("%d",&size);
    int arr[size + 10];

    for(int i = 0; i < size; i++) scanf("%d",&arr[i]);

    int value;
    scanf("%d",&value);

    size = delete_value(arr, size, value);

    for(int i = 0; i < size; i++) printf("%d ",arr[i]);

    return 0;
}