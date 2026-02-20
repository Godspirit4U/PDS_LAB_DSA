// Insert an element in a sorted array at the correct position.

#include <stdio.h>

int insert_sorted(int arr[], int size, int num) {

    int i;

    for(i = size - 1; i >= 0 && arr[i] > num; i--) {
        arr[i + 1] = arr[i];
    }

    arr[i + 1] = num;

    return size + 1;
}

int is_sorted(int arr[], int size) {

    for(int i = 0; i < size - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            return 0;
        }
    }

    return 1;
}

int main() {

    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size + 10];

    printf("Enter sorted array elements:\n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    if(is_sorted(arr, size) == 0) {
        printf("Array is not sorted.\n");
        return 0;
    }
    printf("Original array:\n");
    for(int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }

    int num;
    printf("Enter element to insert: ");
    scanf("%d", &num);

    size = insert_sorted(arr, size, num);

    printf("Updated sorted array:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}