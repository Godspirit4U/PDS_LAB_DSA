#include <stdio.h>

int main() {

    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size + 50];

    for(int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Initial array:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    int no_of_inputs;
    printf("\nEnter the number of elements to insert: ");
    scanf("%d", &no_of_inputs);

    for(int i = 0; i < no_of_inputs; i++) {
        int num;
        printf("Enter the number: ");
        scanf("%d", &num);

        arr[size] = num;
        size++;

        printf("Array after insertion %d:\n", i + 1);
        for(int j = 0; j < size; j++) {
            printf("%d ", arr[j]);
        }
    }
    return 0;
}